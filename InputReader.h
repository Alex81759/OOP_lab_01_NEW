#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <memory>
#include <string>
#include "FigureParameters.h"
#include "FigureType.h"

class InputReader {
    private:
        enum MinAndMaxValue {
            minMenuValue = 0,
            minFigureMenuValue = 1,
            maxMenuValue = 7,
            maxFigureMenuValue = 3
        };
        Point readPoint(const std::string& prompt) const;
    public:
        int readMenuChoice() const;
        int readFigureMenuChoice() const;
        int readFigureTypeChoice() const;
        std::size_t readFigureIndex(std::size_t maxIndex) const;
        double readDouble(const std::string& text) const;
        std::string readNonEmptyString(const std::string& text) const;
        std::unique_ptr<FigureParameters> readFigureParameters(FigureType type) const;
};

#endif // INPUTREADER_H
