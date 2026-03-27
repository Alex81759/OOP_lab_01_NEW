#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <memory>
#include <string>
#include "figureParameters.h"

class InputReader {
    private:
        static const int minMenuValue = 0;
        static const int minFigureMenuValue = 1;
        static const int maxMenuValue = 7;
        static const int maxFigureMenuValue = 3;
        Point readPoint(const std::string& prompt) const;
    public:
        int readMenuChoice() const;
        int readFigureMenuChoice() const;
        int readFigureTypeChoice() const;
        std::size_t readFigureIndex(std::size_t maxIndex) const;
        double readDouble(const std::string& text) const;
        std::string readNonEmptyString(const std::string& text) const;
        std::unique_ptr<FigureParameters> readFigureParameters(const std::type_info&  type) const;
};

#endif // INPUTREADER_H
