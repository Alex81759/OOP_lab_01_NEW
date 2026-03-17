#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <memory>
#include <string>
#include "FigureParameters.h"
#include "FigureType.h"

class InputReader {
public:
    int readMenuChoice(int minValue, int maxValue) const;
    int readFigureTypeChoice() const;
    std::size_t readFigureIndex(std::size_t maxIndex) const;
    double readDouble(const std::string& prompt) const;
    std::string readNonEmptyString(const std::string& prompt) const;
    std::unique_ptr<FigureParameters> readFigureParameters(FigureType type) const;
private:
    Point readPoint(const std::string& prompt) const;
};

#endif // INPUTREADER_H
