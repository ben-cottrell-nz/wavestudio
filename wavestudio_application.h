//
// Created by ben on 19/08/21.
//

#ifndef WAVESTUDIO_WAVESTUDIO_APPLICATION_H
#define WAVESTUDIO_WAVESTUDIO_APPLICATION_H

#include <iostream>
#include <sstream>
#include <vector>
#include <filesystem>

class WaveStudioApplication {
public:
    int run();

private:
    void showAppMainMenuBar();

    void setFont();

    void setColors();

    void showTrackContent();

    void drawTracks();

    void showOpenFileDialog(std::string &, const char *, const char *);

    void showMainWindow();

    void showStartupWindow();

    void newProject();

    struct Track {
        std::string name;
        float gain = 0.5;
        float pan = 0;
        std::vector<double> samples;
    };

    struct Project {
        std::string name;
        std::vector<Track> tracks;
    };

    struct AppState {
        bool intro_window_visible = true;
        bool quit = false;
        bool opening_sound_file = false;
        bool open_file_dialog_visible = false;
        Project project;
        imgui_addons::ImGuiFileBrowser file_dialog;
        double initial_track_width_scale;
    } app_state;
};


#endif //WAVESTUDIO_WAVESTUDIO_APPLICATION_H
