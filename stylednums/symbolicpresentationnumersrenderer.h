#ifndef SYMBOLICPRESENTATIONNUMERSRENDERER_H
#define SYMBOLICPRESENTATIONNUMERSRENDERER_H

#include "stylednumberrenderer.h"

class SymbolicPresentationNumersRenderer : public StyledNumberRenderer
{
public:
    SymbolicPresentationNumersRenderer(int _num);
    SymbolicPresentationNumersRenderer(int _num, QVector<QString> _specificSymbols);

    Style type() const;
    void render(const QStyleOption& _option, const QFont& _font);

private:
    QVector<QString> m_symbols;
};

#endif // SYMBOLICPRESENTATIONNUMERSRENDERER_H
