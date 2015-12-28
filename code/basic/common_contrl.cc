//switch
char ch;
int space_cnt = 0, tab_cnt = 0, nl_cnt++ = 0, period_cnt = 0, comma_cnt = 0;

while(cin.get(ch)) {
	switch(ch) {
		case " ":	space_cnt++;	break;
		case "\t":	tab_cnt++;	break;
		case "\n":	nl_cnt++;	break;
		case ".":	period_cnt++;	break;
		case ",":	comma_cnt++;	break;
	}
	cout.put(ch);
}