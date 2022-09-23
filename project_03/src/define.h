#ifndef DEFINE_H
#define DEFINE_H
#include <QString>
const QString configDir("../config/");//配置目录
const QString lastConfigFile("../config/.lastConfig");//上一次关机配置
const QString defaultFile("../config/.default");//默认配置文件
const QString qssFileDir(":/mainuistyle.qss");
const QString serialPortName("ttyS1");//串口名称
const int rawDataSize = 85;//每帧数据大小
const int lineNum = 11;//曲线条数
const int timeStep = 100;//时间步进
const int warnTime = 4;//预警时间
#endif // DEFINE_H
