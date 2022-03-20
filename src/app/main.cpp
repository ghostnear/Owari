// General app data
#include "appdata.hpp"

// Libraries
#include <core.hpp>
#include <emulators.hpp>

using namespace Core;

// Main entry point
int main(int argc, char* argv[])
{
    // Argument parsing
    ArgParser args(argc, argv);

    // Check main app modes
    if(args.getVersionMode())
        printf("%s\n", OWARI_VERSION.c_str());
    else if(!args.getHelpMode())
    {
        // System variables
        Rendering::Window win;
        StateManager stateManager(&win);

        // CHIP8 mode
        if(args.getEmu() == "CHIP8")
        {
            auto initState = new Emulators::CHIP8();
            stateManager.pushState((State*) initState);
            initState -> loadROM(args.getPath());
        }

        // Main app loop
        while(!win.isQuit())
        {
            // Poll app events
            win.pollEvents();

            // Update the app
            stateManager.update(ImGui::GetIO().Framerate);

            // Draw the app
            win.drawStart();
            stateManager.draw();
            win.drawEnd();

            // Arbitrary value, might need tweaks.
            SDL_Delay(5);
        }
    }

    // Exit
    return EXIT_SUCCESS;
}