
Debian
====================
This directory contains files used to package digidinard/digidinar-qt
for Debian-based Linux systems. If you compile digidinard/digidinar-qt yourself, there are some useful files here.

## digidinar: URI support ##


digidinar-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install digidinar-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your digidinar-qt binary to `/usr/bin`
and the `../../share/pixmaps/digidinar128.png` to `/usr/share/pixmaps`

digidinar-qt.protocol (KDE)

