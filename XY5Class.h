#ifndef XY5_CLASS_H
#define XY5_CLASS_H

#include "Print.h"

#define XY5_HEADER          (0x80)
#define XY5_WRITE_COMMAND   (0x83)
#define XY5_ENDBYTE         (0x8f)

#define XY5_FONT_WIDTH      (4)

class Stream;

class XY5Class : public Print {
  public:
    XY5Class(Stream *port);

    void begin(int displayWidth, int bufferWidth, int address);
    void clear();
    void home();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    virtual size_t write(uint8_t c);

    int set(int x, int y);
    int unset(int x, int y);
    int setCursor(int x);
    int setWindow(int x);
    void flush();

    using Print::write;

  private:
    Stream *port;
    int displayWidth;
    int bufferWidth;
    int address;
    int cursor;
    int window;
    uint8_t *buffer;
    static const uint8_t fontData[];
};

#endif /* XY5_CLASS_H */

