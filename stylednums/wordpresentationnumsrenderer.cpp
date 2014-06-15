#include <QVector>
#include <QPainter>

#include "wordpresentationnumsrenderer.h"

static QVector<QString> words;

WordPresentationNumsRenderer::WordPresentationNumsRenderer(int _num)
    : StyledNumberRenderer(_num)
{
    if(words.isEmpty())
        words << QString::fromLocal8Bit("Ноль")
              << QString::fromLocal8Bit("Один")
              << QString::fromLocal8Bit("Два")
              << QString::fromLocal8Bit("Три")
              << QString::fromLocal8Bit("Четыре")
              << QString::fromLocal8Bit("Пять")
              << QString::fromLocal8Bit("Шесть")
              << QString::fromLocal8Bit("Семь")
              << QString::fromLocal8Bit("Восемь")
              << QString::fromLocal8Bit("Девять");
}

Style WordPresentationNumsRenderer::type() const
{
    return Words;
}

void WordPresentationNumsRenderer::render(const QStyleOption &_option, const QFont &_font)
{
    renderWithText(_option, _font, words[m_num]);
}
