#include "box.h"

Box::Box(double x0, double x1, double y0, double y1, double z0, double z1):
xsides(x0, x1), ysides(y0, y1), zsides(z0, z1) {}
[[nodiscard]] bool Box::isFixedx() const {
    return xsides.isOnePoint();
}
[[nodiscard]] bool Box::isFixedy() const {
    return ysides.isOnePoint();
}
[[nodiscard]] bool Box::isFixedz() const {
    return zsides.isOnePoint();
}
Vector Box::rand(Box box) {
    return {Range::rand(box.xsides), Range::rand(box.ysides), Range::rand(box.zsides)};
}

Box Box::innerBox(double marginx, double marginy, double marginz) {
    return {xsides.left + marginx, xsides.right - marginx,
            ysides.left + marginy, ysides.right - marginy,
            zsides.left + marginz, zsides.right - marginz};
}

