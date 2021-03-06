#pragma once
#include "Engine/Point.h"
#include "Engine/Log.h"

#include "src/Application/GameWindowHandler.h"


using Application::GameWindowHandler;


class Mouse;
class OSWindow {
 public:
    OSWindow();

    virtual void SetFullscreenMode() = 0;
    virtual void SetWindowedMode(int new_window_width, int new_window_height) = 0;
    virtual void SetCursor(const char *cursor_name) = 0;

    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
    virtual unsigned int GetWidth() const = 0;
    virtual unsigned int GetHeight() const = 0;

    virtual Point TransformCursorPos(Point &pt) const = 0;  // screen to client

    virtual bool OnOSMenu(int item_id) = 0;

    virtual void Show() = 0;
    virtual bool Focused() = 0;
    virtual void Activate() = 0;

    virtual void PeekSingleMessage() = 0;
    virtual void PeekMessageLoop() = 0;

    virtual void *GetWinApiHandle() = 0;

    // window-renderer integration, probably should be a separate class
    virtual void OpenGlCreate() = 0;
    virtual void OpenGlSwapBuffers() = 0;

 protected:
    GameWindowHandler *gameCallback = nullptr;
    Log *log = nullptr;
};

extern OSWindow *window;
