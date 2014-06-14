#include <QDebug>
#include <QPainter>

#include "symbolicpresentationnumersrenderer.h"

static QVector<QString> defaultSymbols;

SymbolicPresentationNumersRenderer::SymbolicPresentationNumersRenderer(int _num)
    : StyledNumberRenderer(_num)
{
    if(defaultSymbols.isEmpty())
      defaultSymbols << QString::fromLocal8Bit("♠")
                     << QString::fromLocal8Bit("♥")
                     << QString::fromLocal8Bit("♦")
                     << QString::fromLocal8Bit("♣");

    m_symbols << defaultSymbols;
}

SymbolicPresentationNumersRenderer::SymbolicPresentationNumersRenderer(int _num, QVector<QString> _specificSymbols)
    : StyledNumberRenderer(_num),
      m_symbols(_specificSymbols)
{
    if(m_symbols.isEmpty())
        qDebug() << "empty symbol list! in " << Q_FUNC_INFO;
}

Style SymbolicPresentationNumersRenderer::type() const
{
    return SymbolicNum;
}

void SymbolicPresentationNumersRenderer::render(const QStyleOption &_option, const QFont &_font)
{
    int randomSymbol = qrand() % m_symbols.size();
    QString s(m_num, m_symbols[randomSymbol][0]);
    renderWithText(_option, _font, s);
}
