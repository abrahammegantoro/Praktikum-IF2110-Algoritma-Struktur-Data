# include "valid.h"

Stack validParantheses(char* input, int length){
    Stack S;
    CreateEmpty(&S);
    int i;
    for(i=0; i<length; i++){
        if(input[i] == '(' && input[i+1] == ')'){
            Push(&S, '(');
            Push(&S, ')');
        } else if(input[i] == '{' && input[i+1] == '}'){
            Push(&S, '{');
            Push(&S, '}');
        } else if(input[i] == '[' && input[i+1] == ']'){
            Push(&S, '[');
            Push(&S, ']');
        }
    }
    return S;
}
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/