#include "header/chip8.hpp"

namespace Emulators
{
    void CHIP8::init()
    {
        parent -> getWindow() -> setWindowTitle("Owari | CHIP8");
        state = new CHIP8State();
        cpu = new CHIP8Interpreter();
    }

    void CHIP8::draw()
    {
        ImGui::Begin("Test");                          // Create a window called "Hello, world!" and append into it.
        ImGui::Text("Performance %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
    
    void CHIP8::update(double dt)
    {
        cpu -> update(dt);
    }
};