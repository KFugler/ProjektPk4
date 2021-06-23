#include "file.h"

File::File() {}

File::File(QString name)
{
    filename = name;
    isfirst = true;
}

File::~File() {}

void File::endrow()
{
   write("\n");
   isfirst = true;
}

QVector<QVector<QString>>File::read()
{
    QVector<QVector<QString>> values;

    QFile inputFile(filename);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QVector<QString> line_values;
          QString line = in.readLine();
          QRegularExpression rx (";");
          QStringList list = line.split(rx);
          for(int i=0;i<list.size();i++)
              line_values.push_back(list[i]);

          values.push_back(line_values);
       }
       inputFile.close();
    }
    return values;
}

void File::write(QString value)
{
    QFile outputFile(filename);
    if (outputFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
       QTextStream fs( &outputFile );
       if (!isfirst && value!= "\n")
        {
          fs << ";";
        }
       else
       {
           isfirst = false;
       }
       fs << value;
    }
    outputFile.close();
}
