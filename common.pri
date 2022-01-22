

CONFIG(release, release|debug) {
    SY_DESTDIR = $OUT_PWD/../../SYFileMagager
    SY_LIBS_DIR = $OUT_PWD/../../lib
} else {
    SY_DESTDIR = $OUT_PWD/../../SYFileMagager
    SY_LIBS_DIR = $OUT_PWD/../../lib
}
