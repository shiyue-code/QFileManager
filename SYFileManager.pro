TEMPLATE = subdirs
CONFIG -= ordered
SUBDIRS += framelesshelper src

src.depends += framelesshelper
