/************************************
 * ez.h
 ************************************/

#if(!defined(EZ_H))

/*
 * TODO:
 *
 * - Keys scancode or virtual key code?
 * - Set gamepad deadzone
 * - Test gamepad input
 * - File I/O (only read entire and write entire file)
 * - BMPs support (load and draw image)
 */

// TODO: Eventually remove these: load functions diynamically (and maybe get a base
// version of the structures defined in winbase.h?)
#include <windows.h>
#include <xinput.h>
#include <gl/gl.h>

/*
 * Debug
 */
#define Assert(x) if(!(x)){*((int *)(0))=0;}
#define DEBUG 1
#ifdef DEBUG
#include <stdio.h>
#include <stdarg.h>
void
Printf(char *format, ...)
{
    static char buffer[1024];
    va_list arg_list;
    va_start(arg_list, format);
    vsprintf_s(buffer, sizeof(buffer), format, arg_list);
    va_end(arg_list);
    OutputDebugStringA(buffer);
}
#endif

// TODO: Are these really useful? Maybe when writing windows structs
// to not include windows.h (same thing for xinput.h)
typedef unsigned char       ezu8;
typedef unsigned short      ezu16;
typedef unsigned long       ezu32;
typedef unsigned long long  ezu64;

typedef signed char         ezi8;
typedef signed short        ezi16;
typedef signed long         ezi32;
typedef signed long long    ezi64;

/*
 * Native functions
 */
#define XINPUT_TRIGGER_MAX_VALUE  255
#define XINPUT_STICK_MIN_X       -32768
#define XINPUT_STICK_MAX_X        32767
#define XINPUT_STICK_MIN_Y       -32768
#define XINPUT_STICK_MAX_Y        32767

typedef DWORD (WINAPI *XINPUTGETSTATE)(DWORD, XINPUT_STATE*);
typedef DWORD (WINAPI *XINPUTSETSTATE)(DWORD, XINPUT_VIBRATION*);

#define win32_xinput_process_digital_button(button_ptr, xinput_state, xinput_button)\
    ez_process_digital_button(button_ptr, (((xinput_state).Gamepad.wButtons & (xinput_button)) ? 1 : 0));
#define win32_xinput_process_analog_button(button_ptr, value, max_value)\
    ez_process_analog_button(button_ptr, (float)(value) / (float)(max_value));
#define win32_xinput_process_gamepad_stick(button_ptr, x, max_x, y, max_y)\
    ez_process_gamepad_stick(button_ptr, (float)(x) / (float)(max_x), (float)(y) / (float)(max_y));

typedef struct
ez_win32
{
    // NOTE: Windows
    HWND window;
    HDC dc;

    // NOTE: XInput
    XINPUTGETSTATE xinput_get_state;
    XINPUTSETSTATE xinput_set_state;

    // NOTE: OpenGL
    HGLRC wgl_context;
} ez_win32;

// TODO: Maybe this don't need to be a function
inline static void
win32_xinput_load(ez_win32 *win32)
{
    char *XInputLibs[] = {
        "xinput1_3.dll",
        "xinput1_4.dll",
        "xinput9_1_0.dll",
    };
    HMODULE XInput = 0;
    for(int Index = 0;
        Index < 3; // TODO: Use ArrayCount
        ++Index)
    {
        XInput = LoadLibraryA(XInputLibs[Index]);
        if(XInput)
        {
            break;
        }
    }
    if(XInput)
    {
        win32->xinput_get_state = (XINPUTGETSTATE)GetProcAddress(XInput, "XInputGetState");
        win32->xinput_set_state = (XINPUTSETSTATE)GetProcAddress(XInput, "XInputSetState");
    }
    else
    {
        // TODO: Logging
    }
}

enum
{
    EZ_MAX_MOUSE_BUTTONS = 5,
    EZ_MAX_KEYS          = 256,
    EZ_MAX_GAMEPADS      = 4, // TODO: Should this change based on SO?

    // TODO: Enumerate other key codes.
    // TODO: Key codes should changes based on the SO or
    // I'll do a table to map these codes to the SO codes.
    EZ_KEY_CTRL          = VK_CONTROL,
    EZ_KEY_ALT           = VK_MENU,
    EZ_KEY_SHIFT         = VK_SHIFT,

    EZ_MOUSE_BTN_LEFT    = 0,
    EZ_MOUSE_BTN_MIDDLE  = 1,
    EZ_MOUSE_BTN_RIGHT   = 2,
    EZ_MOUSE_BTN_X1      = 3,
    EZ_MOUSE_BTN_X2      = 4,
};

// Gamepad enum
enum
{
    EZ_GAMEPAD_BTN_A = 0,
    EZ_GAMEPAD_BTN_B,
    EZ_GAMEPAD_BTN_X,
    EZ_GAMEPAD_BTN_Y,
    EZ_GAMEPAD_BTN_UP,
    EZ_GAMEPAD_BTN_DOWN,
    EZ_GAMEPAD_BTN_LEFT,
    EZ_GAMEPAD_BTN_RIGHT,
    EZ_GAMEPAD_BTN_LEFT_BUMPER,
    EZ_GAMEPAD_BTN_RIGHT_BUMPER,
    EZ_GAMEPAD_BTN_LEFT_TRIGGER,
    EZ_GAMEPAD_BTN_RIGHT_TRIGGER,
    EZ_GAMEPAD_BTN_LEFT_STICK,
    EZ_GAMEPAD_BTN_RIGHT_STICK,
    EZ_GAMEPAD_BTN_START,
    EZ_GAMEPAD_BTN_BACK,

    EZ_GAMEPAD_BUTTONS = EZ_GAMEPAD_BTN_BACK,
};

typedef struct
ez_canvas
{
    long int active;
    long int x;
    long int y;
    long int width;
    long int height;
    long int fullscreen;
    char *name;
} ez_canvas;

typedef struct
ez_digital_button
{
    long int down;
    long int pressed;
    long int released;
    long int transitions;
} ez_digital_button;

typedef struct
ez_analog_button
{
    // TODO:
    float value;
    float threshold;
    long int down;
    long int pressed;
    long int released;
    long int transitions;
} ez_analog_button;

typedef struct
ez_mouse
{
    long int          x;
    long int          y;
    long int          z; // mouse wheel
    ez_digital_button buttons[EZ_MAX_MOUSE_BUTTONS];
} ez_mouse;

typedef struct
ez_gamepad_stick
{
    float x;
    float y;
    float threshold_x;
    float threshold_y;
} ez_gamepad_stick;

typedef struct
ez_gamepad
{
    long int connected;
    ez_digital_button a;
    ez_digital_button b;
    ez_digital_button x;
    ez_digital_button y;
    ez_digital_button up;
    ez_digital_button down;
    ez_digital_button left;
    ez_digital_button right;
    ez_digital_button left_bumper;
    ez_digital_button right_bumper;
    ez_digital_button start;
    ez_digital_button back;
    ez_analog_button  left_trigger;
    ez_analog_button  right_trigger;
    ez_gamepad_stick  left_stick;
    ez_gamepad_stick  right_stick;
} ez_gamepad;

typedef struct
ez_input
{
    ez_digital_button keys[EZ_MAX_KEYS];
    ez_mouse          mouse;

    // TODO: Make these two a union?
    ez_gamepad        gamepad;
    ez_gamepad        gamepads[EZ_MAX_GAMEPADS];

    long int          connected_gamepads;
} ez_input;

typedef struct
ez_time
{
    unsigned long long ticks_per_second;
    unsigned long long initial_ticks;
    unsigned long long current_ticks;
    unsigned long long ticks;
    unsigned long long delta_ticks;
    float              delta; // milliseconds
    double             since_start; // milliseconds
} ez_time;

typedef struct
ez
{
    long int  initialized;
    long int  running;
    ez_canvas canvas;
    ez_input  input;
    ez_time   time;

    // Native stuff
    ez_win32  win32;
} ez;

static LRESULT CALLBACK
ez_window_proc(
    HWND   Window,
    UINT   Message,
    WPARAM WParam,
    LPARAM LParam)
{
    LRESULT Result = 0;
    ez *Ez = (ez *)GetWindowLongPtr(Window, GWL_USERDATA);
    switch(Message)
    {
        case WM_ACTIVATE:
        {
#if 0
            Printf("Active: ");
            if(WParam)
            {
                Ez->canvas.active = 1;
                Printf("1\n");
            }
            else
            {
                Ez->canvas.active = 0;
                Printf("0\n");
            }
#endif
        } break;
        case WM_CHAR:
        {
            // TODO: Handle text input
        } break;
        case WM_DESTROY:
        case WM_CLOSE:
        {
            Ez->running = 0;
        } break;
        default:
        {
            Result = DefWindowProcA(Window, Message, WParam, LParam);
        } break;
    }
    return(Result);
}

void
ez_pull_canvas(ez *Ez)
{
    RECT WindowRect;
    GetWindowRect(Ez->win32.window, &WindowRect);
    Ez->canvas.x = WindowRect.left;
    Ez->canvas.y = WindowRect.top;
    RECT ClientRect;
    GetClientRect(Ez->win32.window, &ClientRect);
    Ez->canvas.width  = ClientRect.right - ClientRect.left;
    Ez->canvas.height = ClientRect.bottom - ClientRect.top;

    // TODO: Fetch fullscreen state
}

inline static void
ez_reset_digital_button(ez_digital_button *DigitalButton)
{
    DigitalButton->pressed = 0;
    DigitalButton->released = 0;
    DigitalButton->transitions = 0;
}

inline static void
ez_process_digital_button(
    ez_digital_button *DigitalButton,
    long int IsDown)
{
    if(DigitalButton->down != IsDown)
    {
        DigitalButton->down = IsDown;
        DigitalButton->transitions++;
    }
    if(IsDown && DigitalButton->transitions > 0)
    {
        DigitalButton->pressed = 1;
    }
    else
    {
        DigitalButton->pressed = 0;
    }
    if(IsDown == 0 && DigitalButton->transitions > 0)
    {
        DigitalButton->released = 1;
    }
    else
    {
        DigitalButton->released = 0;
    }
}

inline static void
ez_process_analog_button(
    ez_analog_button *AnalogButton,
    float Value)
{
    if(Value > 1.0f)
    {
        Value = 1.0f;
    }
    else if(Value < 0.0f)
    {
        Value = 0.0f;
    }
    // TODO: Should I clamp to zero?
    if(Value < AnalogButton->threshold)
    {
        Value = 0.0f;
    }
    AnalogButton->value = Value;
    long int WasDown = (AnalogButton->down) ? 1 : 0;
    AnalogButton->down = (Value >= AnalogButton->threshold) ? 1 : 0;
    if(AnalogButton->down != WasDown)
    {
        AnalogButton->transitions++;
    }
    if(AnalogButton->down && AnalogButton->transitions > 0)
    {
        AnalogButton->pressed = 1;
    }
    else
    {
        AnalogButton->pressed = 0;
    }
    if(AnalogButton->down == 0 && AnalogButton->transitions > 0)
    {
        AnalogButton->released = 1;
    }
    else
    {
        AnalogButton->released = 0;
    }
}

inline static void
ez_process_gamepad_stick(
    ez_gamepad_stick *Stick,
    float ValueX,
    float ValueY)
{
    if(ValueX < 0)
    {
        ValueX *= -1.0f;
    }
    if(ValueY < 0)
    {
        ValueY *= -1.0f;
    }
    if(ValueX < Stick->threshold_x)
    {
        ValueX = 0.0f;
    }
    if(ValueY < Stick->threshold_y)
    {
        ValueY = 0.0f;
    }
    Stick->x = ValueX;
    Stick->y = ValueY;
}

void
ez_pull_time(ez *Ez)
{
    LARGE_INTEGER LargeInteger;
    QueryPerformanceCounter(&LargeInteger);
    unsigned long long current_ticks = LargeInteger.QuadPart;

    Ez->time.delta_ticks = current_ticks - Ez->time.initial_ticks - Ez->time.ticks;
    Ez->time.ticks = current_ticks - Ez->time.initial_ticks;

    Ez->time.delta = (float)(1000 * Ez->time.delta_ticks) / (float)Ez->time.ticks_per_second;
    Ez->time.since_start  = (double)(1000 * Ez->time.ticks) / (double)Ez->time.ticks_per_second;
}

void
ez_pull(ez *Ez)
{
    if(Ez->initialized)
    {
        for(int KeyIndex = 0;
            KeyIndex < EZ_MAX_KEYS;
            ++KeyIndex)
        {
            ez_reset_digital_button(&Ez->input.keys[KeyIndex]);
        }
        for(int ButtonIndex = 0;
            ButtonIndex < EZ_MAX_MOUSE_BUTTONS;
            ++ButtonIndex)
        {
            ez_reset_digital_button(&Ez->input.mouse.buttons[ButtonIndex]);
        }
        for(int GamepadIndex = 0;
            GamepadIndex < EZ_MAX_GAMEPADS;
            ++GamepadIndex)
        {
            ez_gamepad *Gamepad = &Ez->input.gamepads[GamepadIndex];
            ez_reset_digital_button(&Gamepad->a);
            ez_reset_digital_button(&Gamepad->b);
            ez_reset_digital_button(&Gamepad->x);
            ez_reset_digital_button(&Gamepad->y);
            ez_reset_digital_button(&Gamepad->up);
            ez_reset_digital_button(&Gamepad->down);
            ez_reset_digital_button(&Gamepad->left);
            ez_reset_digital_button(&Gamepad->right);
            ez_reset_digital_button(&Gamepad->left_bumper);
            ez_reset_digital_button(&Gamepad->right_bumper);
            ez_reset_digital_button(&Gamepad->start);
            ez_reset_digital_button(&Gamepad->back);
        }

        // NOTE: Keyboard pulling
        // TODO: Execute this as a fiber object because when the user
        // is resizing or moving the window the OS will keep spawning
        // message, then the program execution will be stucked in this
        // loop.
        MSG Message;
        while(PeekMessageA(&Message, 0, 0, 0, PM_REMOVE))
        {
            switch(Message.message)
            {
                case WM_KEYUP:
                case WM_KEYDOWN:
                case WM_SYSKEYUP:
                case WM_SYSKEYDOWN:
                {
                    // TODO: We use virtual key code or scancode?
                    long int KeyIndex = Message.wParam;
                    if(KeyIndex < EZ_MAX_KEYS)
                    {
                        long int WasDown = ((Message.lParam & (1 << 30)) != 0) ? 1 : 0;
                        long int IsDown  = ((Message.lParam & (1 << 31)) == 0) ? 1 : 0;
                        if(IsDown != WasDown)
                        {
                            ez_process_digital_button(
                                &Ez->input.keys[KeyIndex],
                                IsDown);
                        }
                    }
                } break;
                default:
                {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                } break;
            }

            // NOTE: Mouse pulling
            POINT MousePosition;
            GetCursorPos(&MousePosition);
            ScreenToClient(Ez->win32.window, &MousePosition);
            Ez->input.mouse.x = MousePosition.x;
            Ez->input.mouse.y = MousePosition.y;
            Ez->input.mouse.z = 0; // TODO: Support mouse wheel
            ez_process_digital_button(
                &Ez->input.mouse.buttons[EZ_MOUSE_BTN_LEFT],
                (GetKeyState(VK_LBUTTON) & (1 << 15)) > 0 ? 1 : 0);
            ez_process_digital_button(
                &Ez->input.mouse.buttons[EZ_MOUSE_BTN_MIDDLE],
                (GetKeyState(VK_MBUTTON) & (1 << 15)) > 0 ? 1 : 0);
            ez_process_digital_button(
                &Ez->input.mouse.buttons[EZ_MOUSE_BTN_RIGHT],
                (GetKeyState(VK_RBUTTON) & (1 << 15)) > 0 ? 1 : 0);
            ez_process_digital_button(
                &Ez->input.mouse.buttons[EZ_MOUSE_BTN_X1],
                (GetKeyState(VK_XBUTTON1) & (1 << 15)) > 0 ? 1 : 0);
            ez_process_digital_button(
                &Ez->input.mouse.buttons[EZ_MOUSE_BTN_X2],
                (GetKeyState(VK_XBUTTON2) & (1 << 15)) > 0 ? 1 : 0);

            // NOTE: Gamepad pulling
            if(Ez->win32.xinput_get_state)
            {
                long int connected_gamepads = 0;
                XINPUT_STATE XInputState;
                for(int Index = 0;
                    Index < EZ_MAX_GAMEPADS;
                    ++Index)
                {
                    ez_gamepad *Gamepad = &Ez->input.gamepads[EZ_MAX_GAMEPADS];
                    DWORD XInputError = Ez->win32.xinput_get_state(Index, &XInputState);
                    if(XInputError == ERROR_SUCCESS)
                    {
                        Gamepad->connected = 1;
                        connected_gamepads++;
                        win32_xinput_process_digital_button(&Gamepad->a,
                            XInputState, XINPUT_GAMEPAD_A);
                        win32_xinput_process_digital_button(&Gamepad->b,
                            XInputState, XINPUT_GAMEPAD_B);
                        win32_xinput_process_digital_button(&Gamepad->x,
                            XInputState, XINPUT_GAMEPAD_X);
                        win32_xinput_process_digital_button(&Gamepad->y,
                            XInputState, XINPUT_GAMEPAD_Y);
                        win32_xinput_process_digital_button(&Gamepad->up,
                            XInputState, XINPUT_GAMEPAD_DPAD_UP);
                        win32_xinput_process_digital_button(&Gamepad->down,
                            XInputState, XINPUT_GAMEPAD_DPAD_DOWN);
                        win32_xinput_process_digital_button(&Gamepad->left,
                            XInputState, XINPUT_GAMEPAD_DPAD_LEFT);
                        win32_xinput_process_digital_button(&Gamepad->right,
                            XInputState, XINPUT_GAMEPAD_DPAD_RIGHT);
                        win32_xinput_process_digital_button(&Gamepad->left_bumper,
                            XInputState, XINPUT_GAMEPAD_LEFT_SHOULDER);
                        win32_xinput_process_digital_button(&Gamepad->right_bumper,
                            XInputState, XINPUT_GAMEPAD_RIGHT_SHOULDER);
                        win32_xinput_process_digital_button(&Gamepad->start,
                            XInputState, XINPUT_GAMEPAD_START);
                        win32_xinput_process_digital_button(&Gamepad->back,
                            XInputState, XINPUT_GAMEPAD_BACK);
                        win32_xinput_process_analog_button(&Gamepad->left_trigger,
                            XInputState.Gamepad.bLeftTrigger, XINPUT_TRIGGER_MAX_VALUE);
                        win32_xinput_process_analog_button(&Gamepad->right_trigger,
                            XInputState.Gamepad.bRightTrigger, XINPUT_TRIGGER_MAX_VALUE);
                        win32_xinput_process_gamepad_stick(&Gamepad->left_stick,
                            XInputState.Gamepad.sThumbLX, XINPUT_STICK_MAX_X,
                            XInputState.Gamepad.sThumbLY, XINPUT_STICK_MAX_Y);
                        win32_xinput_process_gamepad_stick(&Gamepad->right_stick,
                            XInputState.Gamepad.sThumbRX, XINPUT_STICK_MAX_X,
                            XInputState.Gamepad.sThumbRY, XINPUT_STICK_MAX_Y);
                    }
                    else if(XInputError == ERROR_DEVICE_NOT_CONNECTED)
                    {
                        Gamepad->connected = 0;
                        if(Gamepad->connected)
                        {
                            // TODO: Zero the struct
                        }
                    }
                }
                Ez->input.connected_gamepads = connected_gamepads;
            }
            Ez->input.gamepad = Ez->input.gamepads[0];
        }
        ez_pull_canvas(Ez);
        ez_pull_time(Ez);
    }
    else
    {
        // TODO: Logging
    }
}

static void
ez_opengl_push(ez *Ez)
{
    SwapBuffers(Ez->win32.dc);
}

void
ez_push(ez *Ez)
{
    ez_opengl_push(Ez);
}

void
ez_update(ez *Ez)
{
    ez_push(Ez);
    ez_pull(Ez);
}

// TODO: Should I make this extern? Maybe not because the user
// simply use this library by including ez.h
int
ez_initialize(ez *Ez)
{
    Ez->running = 0;
    Ez->initialized = 0;

    char *WindowClassName = "ez_window_class";
    DWORD WindowStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
    int WindowX;
    int WindowY;
    int WindowWidth;
    int WindowHeight;

    if(!Ez->canvas.name)
    {
        Ez->canvas.name = "ez";
    }
    if(Ez->canvas.x != 0)
    {
        WindowX = Ez->canvas.x;
    }
    else
    {
        WindowX = CW_USEDEFAULT;
    }
    if(Ez->canvas.y != 0)
    {
        WindowY = Ez->canvas.y;
    }
    else
    {
        WindowY = CW_USEDEFAULT;
    }
    if(Ez->canvas.width != 0)
    {
        WindowWidth = Ez->canvas.width;
    }
    else
    {
        WindowWidth  = CW_USEDEFAULT;
    }
    if(Ez->canvas.height != 0)
    {
        WindowHeight = Ez->canvas.height;
    }
    else
    {
        WindowHeight = CW_USEDEFAULT;
    }

    if(WindowWidth != CW_USEDEFAULT && WindowHeight != CW_USEDEFAULT)
    {
        RECT WindowRect;
        WindowRect.left   = 0;
        WindowRect.right  = WindowWidth;
        WindowRect.top    = 0;
        WindowRect.bottom = WindowHeight;
        AdjustWindowRect(&WindowRect, WindowStyle, 0);
        WindowWidth  = WindowRect.right - WindowRect.left;
        WindowHeight = WindowRect.bottom - WindowRect.top;
    }

    // TODO: Fullscreen
    if(Ez->canvas.fullscreen)
    {
    }

    WNDCLASSA WindowClass = {0};
    WindowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    WindowClass.lpfnWndProc = ez_window_proc;
    // TODO: Do this
#if 0
    WindowClass.cbClsExtra = ;
    WindowClass.cbWndExtra = ;
    WindowClass.hInstance = ;
    WindowClass.hIcon = ;
    WindowClass.hCursor = ;
    WindowClass.hbrBackground = ;
    WindowClass.lpszMenuName = ;
#endif
    WindowClass.lpszClassName = WindowClassName;
    if(RegisterClassA(&WindowClass))
    {
        Ez->win32.window = CreateWindowExA(
            WS_EX_OVERLAPPEDWINDOW,
            WindowClassName, Ez->canvas.name,
            WindowStyle,
            WindowX, WindowY,
            WindowWidth, WindowHeight,
            0, 0, 0, 0);
        if(Ez->win32.window)
        {
            SetWindowLongPtr(Ez->win32.window, GWL_USERDATA, (LONG_PTR)Ez);

            LARGE_INTEGER LargeInteger = {0};
            QueryPerformanceFrequency(&LargeInteger);
            if(LargeInteger.QuadPart > 0)
            {
                // NOTE: Initialize XInput
                win32_xinput_load(&Ez->win32);
                for(int Index = 0;
                    Index < EZ_MAX_GAMEPADS;
                    ++Index)
                {
                    float trigger_threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD / XINPUT_TRIGGER_MAX_VALUE;
                    Ez->input.gamepads[Index].left_trigger.threshold = trigger_threshold;
                    float stick_threshold_x = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / XINPUT_STICK_MAX_X;
                    float stick_threshold_y = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / XINPUT_STICK_MAX_Y;
                    Ez->input.gamepads[Index].left_stick.threshold_x = stick_threshold_x;
                    Ez->input.gamepads[Index].left_stick.threshold_y = stick_threshold_y;
                    Ez->input.gamepads[Index].right_stick.threshold_x = stick_threshold_x;
                    Ez->input.gamepads[Index].right_stick.threshold_y = stick_threshold_y;
                }

                // NOTE: Initialize OpenGL
                // TODO: What if OpenGL fails?
                // Maybe the user should continue to use the app but with
                // software rendering
                HDC DeviceContext = GetDC(Ez->win32.window);
                PIXELFORMATDESCRIPTOR Pfd;
                Pfd.nSize = sizeof(Pfd);
                Pfd.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
                Pfd.iPixelType = PFD_TYPE_RGBA;
                Pfd.cColorBits = 24;
                Pfd.cAlphaBits = 0;
                Pfd.cDepthBits = 24;
                Pfd.cStencilBits = 8;
                int PixelFormat = ChoosePixelFormat(DeviceContext, &Pfd);
                if(PixelFormat)
                {
                    if(DescribePixelFormat(DeviceContext, PixelFormat, sizeof(Pfd), &Pfd))
                    {
                        SetPixelFormat(DeviceContext, PixelFormat, &Pfd);
                        Ez->win32.wgl_context = wglCreateContext(DeviceContext);
                        if(Ez->win32.wgl_context && wglMakeCurrent(DeviceContext, Ez->win32.wgl_context))
                        {
                            Ez->win32.dc = DeviceContext;

                            // TODO: This should be done before or after loading xinput?
                            // (should include initialization timing or not?)
                            Ez->time.ticks_per_second = LargeInteger.QuadPart;
                            QueryPerformanceCounter(&LargeInteger);
                            Ez->time.initial_ticks = LargeInteger.QuadPart;

                            ez_pull(Ez);
                            Ez->initialized = 1;
                            Ez->running = 1;
                        }
                        else
                        {
                            // TODO: Logging
                            return(0);
                        }
                    }
                    else
                    {
                        // TODO: Logging
                        return(0);
                    }
                }
                else
                {
                    // TODO: Logging
                    return(0);
                }
            }
            else
            {
                // TODO: Logging
                return(0);
            }
        }
        else
        {
            // TODO: Logging
            return(0);
        }
    }
    else
    {
        // TODO: Logging
        return(0);
    }
    return(1);
}

#define EZ_H
#endif

/************************************
 * User program (example code)
 ************************************/
//#include "ez.h"
int
WinMain(
    HINSTANCE Instance,
    HINSTANCE PrevInstance,
    LPSTR     CommandLine,
    int       ShowCommand)
{
    ez Ez = {0};
    Ez.canvas.name = "Code example ez";
    Ez.canvas.width = 800;
    Ez.canvas.height = 600;
    char temp[300];
    if(ez_initialize(&Ez))
    {
        // Game loop
        while(Ez.running)
        {
            if(Ez.input.keys['A'].down)
            {
                glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
            }
            else
            {
                glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
            }
            glClear(GL_COLOR_BUFFER_BIT);

            glViewport(0, 0, Ez.canvas.width, Ez.canvas.height);
            glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 1.0f);
            glVertex2f(-0.5f, -0.5f);
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex2f( 0.5f, -0.5f);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.5f,  0.5f);
            glEnd();

            ez_update(&Ez);
        }
    }
    else
    {
        return(1);
    }
    return(0);
}
