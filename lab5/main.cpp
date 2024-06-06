#include "text.hpp"
#include "sortword.hpp"

// task from 3 lab: Відсортувати слова заданого тексту за зростанням кількості в них заданої літери.



int32_t main()
{
    Letter h('h'), e('e'), l('l'), o('o'), m('m'), y('y'), n('n'), a('a'), v('V'), d('d'),
           i('i'), s('s'), new_row('\n');

    Word word_1;
    word_1.addLetter(h);
    word_1.addLetter(e);
    word_1.addLetter(l);
    word_1.addLetter(l);
    word_1.addLetter(o);

    word_1.printWord();
    new_row.printLetter();

    Word word_2;
    word_2.addLetter(m);
    word_2.addLetter(y);

    word_2.printWord();
    new_row.printLetter();

    Word word_3;
    word_3.addLetter(n);
    word_3.addLetter(a);
    word_3.addLetter(m); 
    word_3.addLetter(e);

    word_3.printWord();
    new_row.printLetter();

    PunctuationMark punctuation_mark('-');

    Word word_4;
    word_4.addLetter(i);
    word_4.addLetter(s);

    word_4.printWord();
    new_row.printLetter();

    Word word_5;
    word_5.addLetter(v);
    word_5.addLetter(l);
    word_5.addLetter(a);
    word_5.addLetter(d);

    word_5.printWord();
    new_row.printLetter();

    Sentence sentence_1;
    sentence_1.addWord(word_1);
    
    sentence_1.printSentence();
    new_row.printLetter();

    Sentence sentence_2;
    sentence_2.addWord(word_2);
    sentence_2.addWord(word_3);
    sentence_2.addWord(word_4);
    sentence_2.addPunctionMark(punctuation_mark);
    sentence_2.addWord(word_5);

    sentence_2.printSentence();
    new_row.printLetter();

    Text text;
    text.addSentence(sentence_1);
    text.addSentence(sentence_2);

    text.printText();
    new_row.printLetter();

    SortWords sort(sentence_2);
    sort.sortWords();

    return 0;
}