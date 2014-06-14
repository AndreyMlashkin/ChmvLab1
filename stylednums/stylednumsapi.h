#ifndef STYLEDNUMSAPI_H
#define STYLEDNUMSAPI_H

#include <QFont>
#include <QVector>
#include <QColor>

enum Style {ArabNums, RomeNums, Words, SymbolicNum, StylesCount};
static QFont defaultStringsFont("Times New Roman", 20);

inline void inc(Style& _style)
{
    unsigned int tmp = static_cast<unsigned int>(_style);
    _style = static_cast<Style>(++tmp);
}

inline QString randomColor()
{
    static QVector<QString> colors;
    if(colors.isEmpty())
    {
        foreach(QString s, QColor::colorNames())
            colors << s;
    }

    int randomNum = qrand() % colors.size();
    return colors[randomNum];
}

inline QVector<QString> stylesNames()
{
    static QVector<QString> stylesNames;
    if(stylesNames.isEmpty())
        stylesNames << QString::fromLocal8Bit("Арабские числа")
                    << QString::fromLocal8Bit("Римские числа")
                    << QString::fromLocal8Bit("Словестное представление")
                    << QString::fromLocal8Bit("Символы");
    return stylesNames;
}

#endif // STYLEDNUMSAPI_H
