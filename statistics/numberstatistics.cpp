#include "numberstatistics.h"
#include "../stylednums/stylednumberrenderer.h"

NumberStatistics::NumberStatistics(StatTypes _type)
  : m_type(_type)
{
  m_description << QString::fromLocal8Bit("Ноль")
                << QString::fromLocal8Bit("Один")
                << QString::fromLocal8Bit("Два")
                << QString::fromLocal8Bit("Три")
                << QString::fromLocal8Bit("Четыре")
                << QString::fromLocal8Bit("Пять")
                << QString::fromLocal8Bit("Шесть")
                << QString::fromLocal8Bit("Семь")
                << QString::fromLocal8Bit("Восемь")
                << QString::fromLocal8Bit("Девять");
    m_statistics.resize(m_description.size());
}

void NumberStatistics::addUserStats(const QList<StyledNumberRenderer *> &_showedData, const QList<int> &_userCheckedData)
{
    foreach (StyledNumberRenderer* renderer, _showedData)
    {
        int generatedNum = renderer->num();

        bool needInc = _userCheckedData.contains(generatedNum);
        needInc ^= !(m_type == NumberSuccess);

        if(needInc)
            m_statistics[generatedNum]++;
    }
}

StatTypes NumberStatistics::type() const
{
    return m_type;
}
