#ifndef Sound_H
#define Sound_H

#include <QObject>
#include <QIODevice>

class Sound:public QIODevice
{
public:
    Sound();
    Sound(int _fq, int _vol);

    void setFreq(int fq);
    void setVolume(int vol);

protected:
    qint64 readData(char *data, qint64 maxlen);
    qint64 writeData(const char *data, qint64 len);
private:
    double frequency=1000;
    double volume=50;

    qint64 it=0;

    QList<char> m_data;
    void appendData();
};

#endif // Sound_H
