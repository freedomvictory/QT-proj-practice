#include "mysyntaxhighlighter.h"

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument * parent) :
    QSyntaxHighlighter(parent)
{

}

void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    /*once changed the text, this function will be handled */
    /*set format of showing */


    QTextCharFormat myFormat;
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);

    QString pattern = "\\bchar\\b"; // a reg-exp
    QRegExp expression(pattern);
    int index = text.indexOf(expression);

    while(index >= 0)
    {
        int length = expression.matchedLength();
        setFormat(index, length, myFormat);
        index = text.indexOf(expression, index + length);
    }
}
