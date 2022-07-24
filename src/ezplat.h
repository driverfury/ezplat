#ifndef EZPLAT_H
#define EZPLAT_H

/**
 * Definitions
 */

#define EZ_MAX_MOUSE_BUTTONS 5
#define EZ_MAX_KEYS 256
#define EZ_MAX_GAMEPADS 4

#ifdef _WIN32

/**
 * NOTE: I need the windows.h because I need to map ez keys to OS keys.
 * TODO: Declare the enumeration inside an preprocessor if, based on the OS.
 */
#include <windows.h>

typedef enum
{
                                                    // 0x00-07 Undefined
EZ_KEY_BACK = VK_BACK,	                            // 0x08
EZ_KEY_TAB = VK_TAB,                                // 0x09
                                                    // 0x0A-0B Undefined
EZ_KEY_CLEAR = VK_CLEAR,                            // 0x0C
EZ_KEY_RETURN = VK_RETURN,                          // 0x0D
                                                    // 0x0E-0F Undefined
EZ_KEY_SHIFT = VK_SHIFT,	                        // 0x10
EZ_KEY_CONTROL = VK_CONTROL,                        // 0x11
EZ_KEY_MENU = VK_MENU,	                            // 0x12
EZ_KEY_PAUSE = VK_PAUSE,	                        // 0x13
EZ_KEY_CAPITAL = VK_CAPITAL,                        // 0x14
                                                    // 0x15-1A Undefined
EZ_KEY_ESCAPE = VK_ESCAPE,	                        // 0x1B
                                                    // 0x1C-1F Undefined
EZ_KEY_SPACE = VK_SPACE,	                        // 0x20
EZ_KEY_PAGE_UP = VK_PRIOR,	                        // 0x21
EZ_KEY_PAGE_DOWN = VK_NEXT,	                        // 0x22
EZ_KEY_END = VK_END,	                            // 0x23
EZ_KEY_HOME = VK_HOME,	                            // 0x24
EZ_KEY_LEFT = VK_LEFT,	                            // 0x25
EZ_KEY_UP = VK_UP,	                                // 0x26
EZ_KEY_RIGHT = VK_RIGHT,	                        // 0x27
EZ_KEY_DOWN = VK_DOWN,	                            // 0x28
EZ_KEY_SELECT = VK_SELECT,	                        // 0x29
EZ_KEY_PRINT = VK_PRINT,	                        // 0x2A
EZ_KEY_EXECUTE = VK_EXECUTE,	                    // 0x2B
EZ_KEY_SNAPSHOT = VK_SNAPSHOT,	                    // 0x2C
EZ_KEY_INSERT = VK_INSERT,	                        // 0x2D
EZ_KEY_DELETE = VK_DELETE,	                        // 0x2E
EZ_KEY_HELP = VK_HELP,	                            // 0x2F
EZ_KEY_0 = 0x30,                                    // 0x30
EZ_KEY_1 = 0x31,                                    // 0x31
EZ_KEY_2 = 0x32,                                    // 0x32
EZ_KEY_3 = 0x33,                                    // 0x33
EZ_KEY_4 = 0x34,                                    // 0x34
EZ_KEY_5 = 0x35,                                    // 0x35
EZ_KEY_6 = 0x36,                                    // 0x36
EZ_KEY_7 = 0x37,                                    // 0x37
EZ_KEY_8 = 0x38,                                    // 0x38
EZ_KEY_9 = 0x39,                                    // 0x39
                                                    // 0x3A-40 Undefined
EZ_KEY_A = 0x41,                                    // 0x41
EZ_KEY_B = 0x42,                                    // 0x42
EZ_KEY_C = 0x43,                                    // 0x43
EZ_KEY_D = 0x44,                                    // 0x44
EZ_KEY_E = 0x45,                                    // 0x45
EZ_KEY_F = 0x46,                                    // 0x46
EZ_KEY_G = 0x47,                                    // 0x47
EZ_KEY_H = 0x48,                                    // 0x48
EZ_KEY_I = 0x49,                                    // 0x49
EZ_KEY_J = 0x4A,                                    // 0x4A
EZ_KEY_K = 0x4B,                                    // 0x4B
EZ_KEY_L = 0x4C,                                    // 0x4C
EZ_KEY_M = 0x4D,                                    // 0x4D
EZ_KEY_N = 0x4E,                                    // 0x4E
EZ_KEY_O = 0x4F,                                    // 0x4F
EZ_KEY_P = 0x50,                                    // 0x50
EZ_KEY_Q = 0x51,                                    // 0x51
EZ_KEY_R = 0x52,                                    // 0x52
EZ_KEY_S = 0x53,                                    // 0x53
EZ_KEY_T = 0x54,                                    // 0x54
EZ_KEY_U = 0x55,                                    // 0x55
EZ_KEY_V = 0x56,                                    // 0x56
EZ_KEY_W = 0x57,                                    // 0x57
EZ_KEY_X = 0x58,                                    // 0x58
EZ_KEY_Y = 0x59,                                    // 0x59
EZ_KEY_Z = 0x5A,                                    // 0x5A
EZ_KEY_LWIN = VK_LWIN,	                            // 0x5B
EZ_KEY_RWIN = VK_RWIN,	                            // 0x5C
EZ_KEY_APPS = VK_APPS,	                            // 0x5D
                                                    // 0x5E Undefined
EZ_KEY_SLEEP = VK_SLEEP,	                        // 0x5F
EZ_KEY_NUMPAD0 = VK_NUMPAD0,	                    // 0x60
EZ_KEY_NUMPAD1 = VK_NUMPAD1,	                    // 0x61
EZ_KEY_NUMPAD2 = VK_NUMPAD2,	                    // 0x62
EZ_KEY_NUMPAD3 = VK_NUMPAD3,	                    // 0x63
EZ_KEY_NUMPAD4 = VK_NUMPAD4,	                    // 0x64
EZ_KEY_NUMPAD5 = VK_NUMPAD5,	                    // 0x65
EZ_KEY_NUMPAD6 = VK_NUMPAD6,	                    // 0x66
EZ_KEY_NUMPAD7 = VK_NUMPAD7,	                    // 0x67
EZ_KEY_NUMPAD8 = VK_NUMPAD8,	                    // 0x68
EZ_KEY_NUMPAD9 = VK_NUMPAD9,	                    // 0x69
EZ_KEY_MULTIPLY = VK_MULTIPLY,	                    // 0x6A
EZ_KEY_ADD = VK_ADD,	                            // 0x6B
EZ_KEY_SEPARATOR = VK_SEPARATOR,	                // 0x6C
EZ_KEY_SUBTRACT = VK_SUBTRACT,	                    // 0x6D
EZ_KEY_DECIMAL = VK_DECIMAL,	                    // 0x6E
EZ_KEY_DIVIDE = VK_DIVIDE,	                        // 0x6F
EZ_KEY_F1 = VK_F1,	                                // 0x70
EZ_KEY_F2 = VK_F2,	                                // 0x71
EZ_KEY_F3 = VK_F3,	                                // 0x72
EZ_KEY_F4 = VK_F4,	                                // 0x73
EZ_KEY_F5 = VK_F5,	                                // 0x74
EZ_KEY_F6 = VK_F6,	                                // 0x75
EZ_KEY_F7 = VK_F7,	                                // 0x76
EZ_KEY_F8 = VK_F8,	                                // 0x77
EZ_KEY_F9 = VK_F9,	                                // 0x78
EZ_KEY_F10 = VK_F10,	                            // 0x79
EZ_KEY_F11 = VK_F11,	                            // 0x7A
EZ_KEY_F12 = VK_F12,	                            // 0x7B
EZ_KEY_F13 = VK_F13,	                            // 0x7C
EZ_KEY_F14 = VK_F14,	                            // 0x7D
EZ_KEY_F15 = VK_F15,	                            // 0x7E
EZ_KEY_F16 = VK_F16,	                            // 0x7F
EZ_KEY_F17 = VK_F17,	                            // 0x80
EZ_KEY_F18 = VK_F18,	                            // 0x81
EZ_KEY_F19 = VK_F19,	                            // 0x82
EZ_KEY_F20 = VK_F20,	                            // 0x83
EZ_KEY_F21 = VK_F21,	                            // 0x84
EZ_KEY_F22 = VK_F22,	                            // 0x85
EZ_KEY_F23 = VK_F23,	                            // 0x86
EZ_KEY_F24 = VK_F24,	                            // 0x87
                                                    // 0x88-8F Undefined
EZ_KEY_NUMLOCK = VK_NUMLOCK,                        // 0x90
EZ_KEY_SCROLL = VK_SCROLL,	                        // 0x91
                                                    // 0x92-97 Undefined
EZ_KEY_LSHIFT = VK_LSHIFT,	                        // 0xA0
EZ_KEY_RSHIFT = VK_RSHIFT,	                        // 0xA1
EZ_KEY_LCONTROL = VK_LCONTROL,	                    // 0xA2
EZ_KEY_RCONTROL = VK_RCONTROL,	                    // 0xA3
EZ_KEY_LMENU = VK_LMENU,	                        // 0xA4
EZ_KEY_RMENU = VK_RMENU,	                        // 0xA5
EZ_KEY_BROWSER_BACK = VK_BROWSER_BACK,	            // 0xA6
EZ_KEY_BROWSER_FORWARD = VK_BROWSER_FORWARD,	    // 0xA7
EZ_KEY_BROWSER_REFRESH = VK_BROWSER_REFRESH,	    // 0xA8
EZ_KEY_BROWSER_STOP = VK_BROWSER_STOP,	            // 0xA9
EZ_KEY_BROWSER_SEARCH = VK_BROWSER_SEARCH,	        // 0xAA
EZ_KEY_BROWSER_FAVORITES = VK_BROWSER_FAVORITES,	// 0xAB
EZ_KEY_BROWSER_HOME = VK_BROWSER_HOME,	            // 0xAC
EZ_KEY_VOLUME_MUTE = VK_VOLUME_MUTE,	            // 0xAD
EZ_KEY_VOLUME_DOWN = VK_VOLUME_DOWN,	            // 0xAE
EZ_KEY_VOLUME_UP = VK_VOLUME_UP,	                // 0xAF
EZ_KEY_MEDIA_NEXT_TRACK = VK_MEDIA_NEXT_TRACK,	    // 0xB0
EZ_KEY_MEDIA_PREV_TRACK = VK_MEDIA_PREV_TRACK,	    // 0xB1
EZ_KEY_MEDIA_STOP = VK_MEDIA_STOP,	                // 0xB2
EZ_KEY_MEDIA_PLAY_PAUSE = VK_MEDIA_PLAY_PAUSE,	    // 0xB3
EZ_KEY_LAUNCH_MAIL = VK_LAUNCH_MAIL,	            // 0xB4
EZ_KEY_LAUNCH_MEDIA_SELECT = VK_LAUNCH_MEDIA_SELECT,// 0xB5
EZ_KEY_LAUNCH_APP1 = VK_LAUNCH_APP1,	            // 0xB6
EZ_KEY_LAUNCH_APP2 = VK_LAUNCH_APP2,	            // 0xB7
                                                    // 0xB8-B9 Undefined
EZ_KEY_OEM_1 = VK_OEM_1,	                        // 0xBA
EZ_KEY_OEM_PLUS = VK_OEM_PLUS,	                    // 0xBB
EZ_KEY_OEM_COMMA = VK_OEM_COMMA,                    // 0xBC
EZ_KEY_OEM_MINUS = VK_OEM_MINUS,                    // 0xBD
EZ_KEY_OEM_PERIOD = VK_OEM_PERIOD,	                // 0xBE
EZ_KEY_OEM_2 = VK_OEM_2,	                        // 0xBF
EZ_KEY_OEM_3 = VK_OEM_3,	                        // 0xC0
                                                    // 0xC1-DA Undefined
EZ_KEY_OEM_4 = VK_OEM_4,	                        // 0xDB
EZ_KEY_OEM_5 = VK_OEM_5,	                        // 0xDC
EZ_KEY_OEM_6 = VK_OEM_6,	                        // 0xDD
EZ_KEY_OEM_7 = VK_OEM_7,	                        // 0xDE
EZ_KEY_OEM_8 = VK_OEM_8,	                        // 0xDF
                                                    // 0xE0-E1 Undefined
EZ_KEY_OEM_102 = VK_OEM_102,	                    // 0xE2
                                                    // 0xE3-E4 Undefined
EZ_KEY_PROCESSKEY = VK_PROCESSKEY,	                // 0xE5
                                                    // 0xE6	Undefined
EZ_KEY_PACKET = VK_PACKET,	                        // 0xE7
                                                    // 0xE8-F5 Undefined
EZ_KEY_ATTN = VK_ATTN,	                            // 0xF6
EZ_KEY_CRSEL = VK_CRSEL,	                        // 0xF7
EZ_KEY_EXSEL = VK_EXSEL,	                        // 0xF8
EZ_KEY_EREOF = VK_EREOF,	                        // 0xF9
EZ_KEY_PLAY = VK_PLAY,	                            // 0xFA
EZ_KEY_ZOOM = VK_ZOOM,	                            // 0xFB
EZ_KEY_NONAME = VK_NONAME,	                        // 0xFC
EZ_KEY_PA1 = VK_PA1,	                            // 0xFD
EZ_KEY_OEM_CLEAR = VK_OEM_CLEAR,	                // 0xFE
} ez_key;

#else

#error "OS not supported"

#endif

typedef enum
{
    EZ_MOUSE_BTN_LEFT    = 0,
    EZ_MOUSE_BTN_MIDDLE  = 1,
    EZ_MOUSE_BTN_RIGHT   = 2,
    EZ_MOUSE_BTN_X1      = 3,
    EZ_MOUSE_BTN_X2      = 4,
} ez_mouse_button;

typedef enum
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
} ez_gamepad_button;

typedef enum
{
    EZ_PIXEL_FORMAT_ARGB = 0,
} ez_pixel_format;

typedef struct
ez_canvas
{
    int Active;
    int X;
    int Y;
    int Width;
    int Height;
    int Fullscreen;
    char *Name;
    void *Pixels;
    ez_pixel_format PixelFormat;
} ez_canvas;

typedef struct
ez_digital_button
{
    int Down;
    int Pressed;
    int Released;
    int Transitions;
} ez_digital_button;

typedef struct
ez_analog_button
{
    float Value;
    float Threshold;
    int Down;
    int Pressed;
    int Released;
    int Transitions;
} ez_analog_button;

typedef struct
ez_mouse
{
    int X;
    int Y;
    int Z;
    ez_digital_button Buttons[EZ_MAX_MOUSE_BUTTONS];
} ez_mouse;

typedef struct
ez_gamepad_stick
{
    float X;
    float Y;
    float ThresholdX;
    float ThresholdY;
} ez_gamepad_stick;

typedef struct
ez_gamepad
{
    int Connected;
    ez_digital_button A;
    ez_digital_button B;
    ez_digital_button X;
    ez_digital_button Y;
    ez_digital_button Up;
    ez_digital_button Down;
    ez_digital_button Left;
    ez_digital_button Right;
    ez_digital_button LeftBumper;
    ez_digital_button RightBumper;
    ez_digital_button Start;
    ez_digital_button Back;
    ez_analog_button  LeftTrigger;
    ez_analog_button  RightTrigger;
    ez_gamepad_stick  LeftStick;
    ez_gamepad_stick  RightStick;
} ez_gamepad;

typedef struct
ez_input
{
    ez_digital_button Keys[EZ_MAX_KEYS];
    ez_mouse          Mouse;
    ez_gamepad        Gamepad;
    ez_gamepad        Gamepads[EZ_MAX_GAMEPADS];
    int               ConnectedGamepads;
} ez_input;

#include <inttypes.h>

typedef struct
ez_time
{
    uint64_t TicksPerSecond;
    uint64_t InitialTicks;
    uint64_t CurrentTicks;
    uint64_t Ticks;
    uint64_t DeltaTicks;
    float    Delta; // milliseconds
    double   SinceStart; // milliseconds
} ez_time;

#define EZ_INTERNALS_SIZE  100

#ifdef _WIN32
#define EZ_OS_CONTEXT_SIZE 100
#else
#error "OS not supported"
#endif

typedef struct
ez
{
    int       Initialized;
    int       Running;
    ez_canvas Canvas;
    ez_input  Input;
    ez_time   Time;

    unsigned char Internals[EZ_INTERNALS_SIZE];
    unsigned char OSContext[EZ_OS_CONTEXT_SIZE];
} ez;

/**
 * API
 */

extern int      EzInitialize(ez *Ez);
extern void     EzPush(ez *Ez);
extern void     EzPull(ez *Ez);

#ifdef EZPLAT_IMPLEMENTATION

#ifdef _WIN32

typedef struct
ez_internals
{
    int PrevFullscreen;
} ez_internals;

static ez_internals *
EzGetInternals(ez *Ez)
{
    if(!Ez)
    {
        return(0);
    }

    return((ez_internals *)Ez->Internals);
}

/**
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

/*
 * Debug
 */
#ifdef DEBUG
#include <stdio.h>
#include <stdarg.h>
#if 0
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
#endif

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

typedef struct
ez_win32
{
    // NOTE: Window
    HWND Window;
    WINDOWPLACEMENT WindowPlacement;

    // NOTE: XInput
    XINPUTGETSTATE XInputGetState;
    XINPUTSETSTATE XInputSetState;

    // NOTE: Gfx
    BITMAPINFO BitmapInfo;
} ez_win32;

#if 0
// TODO: Do this in a static way
#if sizeof(ez_win32) < EZ_OS_CONTEXT_SIZE
#error "There's not enough space for OS Context"
#endif
#endif

static ez_win32 *
EzGetWin32Context(ez *Ez)
{
    if(!Ez)
    {
        return(0);
    }

    return((ez_win32 *)Ez->OSContext);
}

// TODO: Maybe this don't need to be a function
inline static void
Win32LoadXInputLibrary(ez_win32 *Win32)
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
        Win32->XInputGetState = (XINPUTGETSTATE)GetProcAddress(XInput, "XInputGetState");
        Win32->XInputSetState = (XINPUTSETSTATE)GetProcAddress(XInput, "XInputSetState");
    }
    else
    {
        // TODO: Logging
    }
}

typedef struct
win32_window_rect
{
    int X;
    int Y;
    int Width;
    int Height;
} win32_window_rect;

static win32_window_rect
Win32GetWindowRect(HWND Window)
{
    win32_window_rect WindowRect = {0};

    RECT TmpRect;
    GetWindowRect(Window, &TmpRect);
    WindowRect.X = TmpRect.left;
    WindowRect.Y = TmpRect.top;
    WindowRect.Width = TmpRect.right - TmpRect.left;
    WindowRect.Height = TmpRect.bottom - TmpRect.top;

    return(WindowRect);
}

static win32_window_rect
Win32GetClientRect(HWND Window)
{
    win32_window_rect ClientRect = {0};

    RECT TmpRect;
    if(GetClientRect(Window, &TmpRect))
    {
        ClientRect.X = TmpRect.left;
        ClientRect.Y = TmpRect.top;
        ClientRect.Width = TmpRect.right - TmpRect.left;
        ClientRect.Height = TmpRect.bottom - TmpRect.top;
    }

    return(ClientRect);
}

static void Win32DisplayBuffer(ez *Ez);

static LRESULT CALLBACK
Win32WindowProc(
    HWND   Window,
    UINT   Message,
    WPARAM WParam,
    LPARAM LParam)
{
    LRESULT Result = 0;

    ez *Ez = (ez *)GetWindowLongPtr(Window, GWLP_USERDATA);
    if(!Ez)
    {
        Result = DefWindowProcA(Window, Message, WParam, LParam);
    }

    ez_win32 *Win32 = EzGetWin32Context(Ez);
    if(!Win32)
    {
        Result = DefWindowProcA(Window, Message, WParam, LParam);
    }

    switch(Message)
    {

#if 0
        case WM_ACTIVATE:
        {
            if(WParam)
            {
                Ez->Canvas.Active = 1;
            }
            else
            {
                Ez->Canvas.Active = 0;
            }
        } break;
#endif

        case WM_DESTROY:
        case WM_CLOSE:
        {
            Ez->Running = 0;
        } break;

        case WM_SIZE:
        {
        } break;

        case WM_PAINT:
        {
            Win32DisplayBuffer(Ez);
        };

        default:
        {
            Result = DefWindowProcA(Window, Message, WParam, LParam);
        } break;
    }

    return(Result);
}

static void
EzPullCanvas(ez *Ez)
{
    ez_win32 *Win32 = EzGetWin32Context(Ez);

    if(Win32)
    {
        win32_window_rect WindowRect = Win32GetWindowRect(Win32->Window);
        Ez->Canvas.X = WindowRect.X;
        Ez->Canvas.Y = WindowRect.Y;
    }

    // TODO: Fetch fullscreen state
}

inline static void
EzResetDigitalButton(ez_digital_button *DigitalButton)
{
    DigitalButton->Pressed = 0;
    DigitalButton->Released = 0;
    DigitalButton->Transitions = 0;
}

inline static void
EzProcessDigitalButton(
    ez_digital_button *DigitalButton,
    int IsDown)
{
    if(DigitalButton->Down != IsDown)
    {
        DigitalButton->Down = IsDown;
        DigitalButton->Transitions++;
    }
    if(IsDown && DigitalButton->Transitions > 0)
    {
        DigitalButton->Pressed = 1;
    }
    else
    {
        DigitalButton->Pressed = 0;
    }
    if(IsDown == 0 && DigitalButton->Transitions > 0)
    {
        DigitalButton->Released = 1;
    }
    else
    {
        DigitalButton->Released = 0;
    }
}

inline static void
EzProcessAnalogButton(
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
    if(Value < AnalogButton->Threshold)
    {
        Value = 0.0f;
    }
    AnalogButton->Value = Value;
    int WasDown = (AnalogButton->Down) ? 1 : 0;
    AnalogButton->Down = (Value >= AnalogButton->Threshold) ? 1 : 0;
    if(AnalogButton->Down != WasDown)
    {
        AnalogButton->Transitions++;
    }
    if(AnalogButton->Down && AnalogButton->Transitions > 0)
    {
        AnalogButton->Pressed = 1;
    }
    else
    {
        AnalogButton->Pressed = 0;
    }
    if(AnalogButton->Down == 0 && AnalogButton->Transitions > 0)
    {
        AnalogButton->Released = 1;
    }
    else
    {
        AnalogButton->Released = 0;
    }
}

inline static void
EzProcessGamepadStick(
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
    if(ValueX < Stick->ThresholdX)
    {
        ValueX = 0.0f;
    }
    if(ValueY < Stick->ThresholdY)
    {
        ValueY = 0.0f;
    }
    Stick->X = ValueX;
    Stick->Y = ValueY;
}

static void
EzPullTime(ez *Ez)
{
    LARGE_INTEGER LargeInteger;
    QueryPerformanceCounter(&LargeInteger);
    uint64_t CurrentTicks = LargeInteger.QuadPart;

    Ez->Time.DeltaTicks = CurrentTicks - Ez->Time.InitialTicks - Ez->Time.Ticks;
    Ez->Time.Ticks = CurrentTicks - Ez->Time.InitialTicks;

    Ez->Time.Delta = (float)(1000 * Ez->Time.DeltaTicks) / (float)Ez->Time.TicksPerSecond;
    Ez->Time.SinceStart  = (double)(1000 * Ez->Time.Ticks) / (double)Ez->Time.TicksPerSecond;
}

#define Win32XInputProcessDigitalButton(ButtonPtr, XInputState, XInputButton)\
    EzProcessDigitalButton((ButtonPtr), (((XInputState).Gamepad.wButtons & (XInputButton)) ? 1 : 0));
#define Win32XInputProcessAnalogButton(ButtonPtr, Value, MaxValue)\
    EzProcessAnalogButton((ButtonPtr), (float)(Value) / (float)(MaxValue));
#define Win32XInputProcessGamepadStick(ButtonPtr, X, MaxX, Y, MaxY)\
    EzProcessGamepadStick((ButtonPtr), (float)(X) / (float)(MaxX), (float)(Y) / (float)(MaxY));

extern void
EzPull(ez *Ez)
{
    if(Ez && Ez->Initialized)
    {
        for(int KeyIndex = 0;
            KeyIndex < EZ_MAX_KEYS;
            ++KeyIndex)
        {
            EzResetDigitalButton(&Ez->Input.Keys[KeyIndex]);
        }
        for(int ButtonIndex = 0;
            ButtonIndex < EZ_MAX_MOUSE_BUTTONS;
            ++ButtonIndex)
        {
            EzResetDigitalButton(&Ez->Input.Mouse.Buttons[ButtonIndex]);
        }
        for(int GamepadIndex = 0;
            GamepadIndex < EZ_MAX_GAMEPADS;
            ++GamepadIndex)
        {
            ez_gamepad *Gamepad = &Ez->Input.Gamepads[GamepadIndex];
            EzResetDigitalButton(&Gamepad->A);
            EzResetDigitalButton(&Gamepad->B);
            EzResetDigitalButton(&Gamepad->X);
            EzResetDigitalButton(&Gamepad->Y);
            EzResetDigitalButton(&Gamepad->Up);
            EzResetDigitalButton(&Gamepad->Down);
            EzResetDigitalButton(&Gamepad->Left);
            EzResetDigitalButton(&Gamepad->Right);
            EzResetDigitalButton(&Gamepad->LeftBumper);
            EzResetDigitalButton(&Gamepad->RightBumper);
            EzResetDigitalButton(&Gamepad->Start);
            EzResetDigitalButton(&Gamepad->Back);
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
                    WPARAM KeyIndex = Message.wParam;
                    if(KeyIndex < EZ_MAX_KEYS)
                    {
                        int WasDown = ((Message.lParam & (1 << 30)) != 0) ? 1 : 0;
                        int IsDown  = ((Message.lParam & (1 << 31)) == 0) ? 1 : 0;
                        if(IsDown != WasDown)
                        {
                            EzProcessDigitalButton(
                                &Ez->Input.Keys[KeyIndex],
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

            ez_win32 *Win32 = EzGetWin32Context(Ez);

            // NOTE: Mouse pulling
            POINT MousePosition;
            GetCursorPos(&MousePosition);
            ScreenToClient(Win32->Window, &MousePosition);
            Ez->Input.Mouse.X = MousePosition.x;
            Ez->Input.Mouse.Y = MousePosition.y;
            Ez->Input.Mouse.Z = 0; // TODO: Support mouse wheel
            EzProcessDigitalButton(
                &Ez->Input.Mouse.Buttons[EZ_MOUSE_BTN_LEFT],
                (GetKeyState(VK_LBUTTON) & (1 << 15)) > 0 ? 1 : 0);
            EzProcessDigitalButton(
                &Ez->Input.Mouse.Buttons[EZ_MOUSE_BTN_MIDDLE],
                (GetKeyState(VK_MBUTTON) & (1 << 15)) > 0 ? 1 : 0);
            EzProcessDigitalButton(
                &Ez->Input.Mouse.Buttons[EZ_MOUSE_BTN_RIGHT],
                (GetKeyState(VK_RBUTTON) & (1 << 15)) > 0 ? 1 : 0);
            EzProcessDigitalButton(
                &Ez->Input.Mouse.Buttons[EZ_MOUSE_BTN_X1],
                (GetKeyState(VK_XBUTTON1) & (1 << 15)) > 0 ? 1 : 0);
            EzProcessDigitalButton(
                &Ez->Input.Mouse.Buttons[EZ_MOUSE_BTN_X2],
                (GetKeyState(VK_XBUTTON2) & (1 << 15)) > 0 ? 1 : 0);

            // NOTE: Gamepad pulling
            if(Win32->XInputGetState)
            {
                int ConnectedGamepads = 0;
                XINPUT_STATE XInputState;
                for(int Index = 0;
                    Index < EZ_MAX_GAMEPADS;
                    ++Index)
                {
                    ez_gamepad *Gamepad = &Ez->Input.Gamepads[EZ_MAX_GAMEPADS];
                    DWORD XInputError = Win32->XInputGetState(Index, &XInputState);
                    if(XInputError == ERROR_SUCCESS)
                    {
                        Gamepad->Connected = 1;
                        ConnectedGamepads++;
                        Win32XInputProcessDigitalButton(&Gamepad->A,
                            XInputState, XINPUT_GAMEPAD_A);
                        Win32XInputProcessDigitalButton(&Gamepad->B,
                            XInputState, XINPUT_GAMEPAD_B);
                        Win32XInputProcessDigitalButton(&Gamepad->X,
                            XInputState, XINPUT_GAMEPAD_X);
                        Win32XInputProcessDigitalButton(&Gamepad->Y,
                            XInputState, XINPUT_GAMEPAD_Y);
                        Win32XInputProcessDigitalButton(&Gamepad->Up,
                            XInputState, XINPUT_GAMEPAD_DPAD_UP);
                        Win32XInputProcessDigitalButton(&Gamepad->Down,
                            XInputState, XINPUT_GAMEPAD_DPAD_DOWN);
                        Win32XInputProcessDigitalButton(&Gamepad->Left,
                            XInputState, XINPUT_GAMEPAD_DPAD_LEFT);
                        Win32XInputProcessDigitalButton(&Gamepad->Right,
                            XInputState, XINPUT_GAMEPAD_DPAD_RIGHT);
                        Win32XInputProcessDigitalButton(&Gamepad->LeftBumper,
                            XInputState, XINPUT_GAMEPAD_LEFT_SHOULDER);
                        Win32XInputProcessDigitalButton(&Gamepad->RightBumper,
                            XInputState, XINPUT_GAMEPAD_RIGHT_SHOULDER);
                        Win32XInputProcessDigitalButton(&Gamepad->Start,
                            XInputState, XINPUT_GAMEPAD_START);
                        Win32XInputProcessDigitalButton(&Gamepad->Back,
                            XInputState, XINPUT_GAMEPAD_BACK);
                        Win32XInputProcessAnalogButton(&Gamepad->LeftTrigger,
                            XInputState.Gamepad.bLeftTrigger, XINPUT_TRIGGER_MAX_VALUE);
                        Win32XInputProcessAnalogButton(&Gamepad->RightTrigger,
                            XInputState.Gamepad.bRightTrigger, XINPUT_TRIGGER_MAX_VALUE);
                        Win32XInputProcessGamepadStick(&Gamepad->LeftStick,
                            XInputState.Gamepad.sThumbLX, XINPUT_STICK_MAX_X,
                            XInputState.Gamepad.sThumbLY, XINPUT_STICK_MAX_Y);
                        Win32XInputProcessGamepadStick(&Gamepad->RightStick,
                            XInputState.Gamepad.sThumbRX, XINPUT_STICK_MAX_X,
                            XInputState.Gamepad.sThumbRY, XINPUT_STICK_MAX_Y);
                    }
                    else if(XInputError == ERROR_DEVICE_NOT_CONNECTED)
                    {
                        Gamepad->Connected = 0;
                        if(Gamepad->Connected)
                        {
                            // TODO: Zero the struct
                        }
                    }
                }
                Ez->Input.ConnectedGamepads = ConnectedGamepads;
            }
            Ez->Input.Gamepad = Ez->Input.Gamepads[0];
        }
        EzPullCanvas(Ez);
        EzPullTime(Ez);
    }
    else
    {
        // TODO: Logging
    }
}

#undef Win32XInputProcessDigitalButton
#undef Win32XInputProcessAnalogButton
#undef Win32XInputProcessGamepadStick

static void
Win32DisplayBuffer(ez *Ez)
{
    ez_win32 *Win32 = EzGetWin32Context(Ez);
    if(Ez && Win32)
    {
        if(Ez->Canvas.Pixels)
        {
            win32_window_rect ClientRect = Win32GetClientRect(Win32->Window);
            HDC DeviceContext = GetDC(Win32->Window);

            StretchDIBits(
                DeviceContext,
                0, 0, ClientRect.Width, ClientRect.Width,
                0, 0, Ez->Canvas.Width, Ez->Canvas.Height,
                Ez->Canvas.Pixels, &Win32->BitmapInfo,
                DIB_RGB_COLORS, SRCCOPY);

            ReleaseDC(Win32->Window, DeviceContext);
        }
    }
}

#define EZ_WIN32_NORMAL_WINDOW_STYLE (WS_OVERLAPPEDWINDOW)

extern void
EzPush(ez *Ez)
{
    ez_internals *Internals = EzGetInternals(Ez);
    ez_win32 *Win32 = EzGetWin32Context(Ez);
    if(Ez && Internals && Win32)
    {
        // Toggle fullscreen
        if(Internals->PrevFullscreen == 0 && Ez->Canvas.Fullscreen != 0)
        {
            DWORD Style = GetWindowLong(Win32->Window, GWL_STYLE);
            Win32->WindowPlacement.length = sizeof(Win32->WindowPlacement);
            MONITORINFO MonitorInfo = {0};
            MonitorInfo.cbSize = sizeof(MonitorInfo);
            if(!GetWindowPlacement(Win32->Window, &Win32->WindowPlacement))
            {
                DWORD Err = GetLastError();
                Err = Err - 1 + 1;
            }

            HMONITOR Monitor = MonitorFromWindow(Win32->Window, MONITOR_DEFAULTTOPRIMARY);
            if(!Monitor)
            {
                DWORD Err = GetLastError();
                Err = Err - 1 + 1;
            }

            if(!GetMonitorInfo(Monitor, &MonitorInfo))
            {
                DWORD Err = GetLastError();
                Err = Err - 1 + 1;
            }

            if( GetWindowPlacement(Win32->Window, &Win32->WindowPlacement) &&
                GetMonitorInfoA(MonitorFromWindow(Win32->Window, MONITOR_DEFAULTTOPRIMARY), &MonitorInfo))
            {
                SetWindowLong(
                    Win32->Window, GWL_STYLE,
                    Style & ~EZ_WIN32_NORMAL_WINDOW_STYLE);
                SetWindowPos(
                    Win32->Window, HWND_TOP,
                    MonitorInfo.rcMonitor.left, MonitorInfo.rcMonitor.top,
                    MonitorInfo.rcMonitor.right - MonitorInfo.rcMonitor.left,
                    MonitorInfo.rcMonitor.bottom - MonitorInfo.rcMonitor.top,
                    SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
            }
        }
        else if(Internals->PrevFullscreen != 0 && Ez->Canvas.Fullscreen == 0)
        {
            DWORD Style = GetWindowLong(Win32->Window, GWL_STYLE);
            SetWindowLong(Win32->Window, GWL_STYLE, Style | EZ_WIN32_NORMAL_WINDOW_STYLE);
            SetWindowPlacement(Win32->Window, &Win32->WindowPlacement);
            SetWindowPos(Win32->Window, 0, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_NOZORDER|SWP_NOOWNERZORDER|SWP_FRAMECHANGED);
        }
        Internals->PrevFullscreen = Ez->Canvas.Fullscreen;

        // Display canvas buffer
        Win32DisplayBuffer(Ez);
    }
}

extern int
EzInitialize(ez *Ez)
{
    Ez->Running = 0;
    Ez->Initialized = 0;

    char *WindowClassName = "ez_window_class";
    DWORD WindowStyle = EZ_WIN32_NORMAL_WINDOW_STYLE;

    if(!Ez->Canvas.Name)
    {
        Ez->Canvas.Name = "ez";
    }

    if(Ez->Canvas.Width <= 0 || Ez->Canvas.Height <= 0)
    {
        // TODO: Logging
        return(0);
    }

    if(Ez->Canvas.PixelFormat != EZ_PIXEL_FORMAT_ARGB)
    {
        // TODO: Logging
        return(0);
    }

    WNDCLASSA WindowClass = {0};
    WindowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    WindowClass.lpfnWndProc = Win32WindowProc;
    WindowClass.cbClsExtra = 0;
    WindowClass.cbWndExtra = 0;
    WindowClass.hInstance = 0;
    WindowClass.hIcon = LoadIcon(0, IDI_APPLICATION);
    WindowClass.hCursor = LoadCursor(0, IDC_ARROW);
    WindowClass.hbrBackground = 0;
    WindowClass.lpszMenuName = 0;
    WindowClass.lpszClassName = WindowClassName;
    if(RegisterClassA(&WindowClass))
    {
        ez_win32 *Win32 = (ez_win32 *)Ez->OSContext;

        RECT WindowRect = {0};
        WindowRect.left   = 0;
        WindowRect.top    = 0;
        WindowRect.right  = Ez->Canvas.Width + WindowRect.left;
        WindowRect.bottom = Ez->Canvas.Height + WindowRect.top;
        if(!AdjustWindowRect(&WindowRect, WindowStyle, 0))
        {
            // TODO: Logging
            return(1);
        }
        int WindowWidth  = WindowRect.right - WindowRect.left;
        int WindowHeight = WindowRect.bottom - WindowRect.top;

        Win32->Window = CreateWindowExA(
            0,
            WindowClass.lpszClassName,
            Ez->Canvas.Name,
            WindowStyle,
            CW_USEDEFAULT, CW_USEDEFAULT,
            WindowWidth, WindowHeight,
            0, 0, 0, 0);
        if(Win32->Window)
        {
            SetWindowLongPtr(Win32->Window, GWLP_USERDATA, (LONG_PTR)Ez);

            // NOTE: If we don't do this non-sense, the GetClientRect() function keeps returning the wrong values.
            SetWindowPos(Win32->Window, 0, 0, 0, 0, 0, SWP_NOMOVE);
            SetWindowPos(Win32->Window, 0, 0, 0, WindowWidth, WindowHeight, SWP_NOMOVE);

            LARGE_INTEGER LargeInteger = {0};
            QueryPerformanceFrequency(&LargeInteger);
            if(LargeInteger.QuadPart > 0)
            {
                Win32LoadXInputLibrary(Win32);
                for(int Index = 0;
                    Index < EZ_MAX_GAMEPADS;
                    ++Index)
                {
                    float trigger_threshold = XINPUT_GAMEPAD_TRIGGER_THRESHOLD / XINPUT_TRIGGER_MAX_VALUE;
                    Ez->Input.Gamepads[Index].LeftTrigger.Threshold = trigger_threshold;
                    float stick_threshold_x = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / XINPUT_STICK_MAX_X;
                    float stick_threshold_y = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / XINPUT_STICK_MAX_Y;
                    Ez->Input.Gamepads[Index].LeftStick.ThresholdX = stick_threshold_x;
                    Ez->Input.Gamepads[Index].LeftStick.ThresholdY = stick_threshold_y;
                    Ez->Input.Gamepads[Index].RightStick.ThresholdX = stick_threshold_x;
                    Ez->Input.Gamepads[Index].RightStick.ThresholdY = stick_threshold_y;
                }
            }
            else
            {
                // TODO: Logging
                return(0);
            }

            Win32->BitmapInfo.bmiHeader.biSize = sizeof(Win32->BitmapInfo.bmiHeader);
            Win32->BitmapInfo.bmiHeader.biWidth = Ez->Canvas.Width;
            Win32->BitmapInfo.bmiHeader.biHeight = -Ez->Canvas.Height;
            Win32->BitmapInfo.bmiHeader.biPlanes = 1;
            Win32->BitmapInfo.bmiHeader.biBitCount = 32;
            Win32->BitmapInfo.bmiHeader.biCompression = BI_RGB;

            ez_internals *Internals = EzGetInternals(Ez);
            if(Internals)
            {
                Internals->PrevFullscreen = 0;
            }

            Ez->Running = 1;
            Ez->Initialized = 1;
            ShowWindow(Win32->Window, SW_SHOW);

            EzPull(Ez);
            EzPush(Ez);
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

#undef EZ_WIN32_NORMAL_WINDOW_STYLE

#undef XINPUT_TRIGGER_MAX_VALUE
#undef XINPUT_STICK_MIN_X
#undef XINPUT_STICK_MAX_X
#undef XINPUT_STICK_MIN_Y
#undef XINPUT_STICK_MAX_Y

#endif

#endif

#endif
