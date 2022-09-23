#include "sound.h"
#include <qmath.h>
#define     SAMPLE_RATE         44100
#define     SAMPLE_COUNT        (SAMPLE_RATE * 0.5)   /* 0.5 seconds */
#define     AMPLITUDE           (1.0 * 0x7F00)
#define     ONE_HZ           (1.0 / SAMPLE_RATE)

Sound::Sound()
{

}

Sound::Sound(int _fq,int _vol)
{
    frequency=_fq;
    volume=_vol;
}

void Sound::setFreq(int _fq)
{
    frequency=_fq;
}

void Sound::setVolume(int _vol)
{
    volume=_vol;
}

qint64 Sound::readData(char *data, qint64 maxlen)
{
    if(m_data.count()==0)
    {
        appendData();
    }
    qint64 count=qMin(maxlen,(qint64)m_data.count());
    for(qint64 i=0;i<count;i++)
    {
        data[i]=m_data[i];
    }
    m_data.erase(m_data.begin(),m_data.begin()+count);
    return count;
}

qint64 Sound::writeData(const char *data, qint64 len)
{
    for(qint64 i=0;i<len;i++)
    {
        m_data.push_back(data[i]);
    }
    return len;
}

void Sound::appendData()
{
    for(qint64 i=it;i<it+SAMPLE_COUNT;i++)
    {
        short temp=(volume/100)*AMPLITUDE * sin (frequency* ONE_HZ * 2 * i * M_PI) ;
        m_data.append((char)temp);
        m_data.append((char)(temp>>8));
        m_data.append((char)temp);
        m_data.append((char)(temp>>8));
    }
    it+=SAMPLE_COUNT;
}
