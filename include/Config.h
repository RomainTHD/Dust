// SPDX-License-Identifier: GPL-3.0-or-later
/**
 * Fichier de configuration
 */
// Created by Romain on 09/07/2020.

#define WIDTH 10
#define HEIGHT 8

#define DISPLAY true

#define BACKGROUND_COLOR "#000000"
#define OUTLINE_THICKNESS 1

#define UPDATES_PER_SECOND 1

#if DISPLAY
#   define FRAMERATE 120
#   define X_SERVER
#   define VSYNC_MODE true
#endif
