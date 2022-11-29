# include "anagramalstrukdat.h"
# include <stdio.h>

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string){
    int len = 0;
    while (string[len] != '\0'){
        len = len + 1;
    }

    return len;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command){
    Word kata;
    kata.Length = stringLength(command);

    for (int i = 0; i < stringLength(command); i++)
    {
        kata.TabWord[i] = command[i];
    }

    return kata;
}

/*  Menerima dua buah parameter yaitu string1 dan string2
    Mengembalikan true apabila string2 merupakan anagram dari string1
    Mengembalikan false apabila string2 bukan merupakan anagram dari string1
    String dianggap anagram apabila disusun dari huruf yang tepat sama */
boolean isAnagram(Word string1, Word string2){
    int i, j;
    boolean found;
    if (string1.Length != string2.Length){
        return false;
    } else {
        for (i = 0; i < string1.Length; i++){
            found = false;
            j = 0;
            while (!found && j < string2.Length){
                if (string1.TabWord[i] == string2.TabWord[j]){
                    found = true;
                } else {
                    j = j + 1;
                }
            }
            if (!found){
                return false;
            }
        }
        return true;
    }
}

/*  Mengembalikan jumlah frekuensi kemunculan anagram alstrukdat 
    pada argumen frek */
void anagramalstrukdat(int* frek){
    Word alstrukdat = toKata("alstrukdat");
    STARTWORD();
    while (!isEndWord()){
        if (isAnagram(alstrukdat, currentWord)){
            *frek = *frek + 1;
        }
        ADVWORD();
    }
}
