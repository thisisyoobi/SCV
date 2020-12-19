int homeDir(char s[], int index)
{
	char *home = "/home";
	int j = 0;

	for( int i=index; i<index+5; i++ ) {
		if( s[i] != home[j] ) {
			return 0;
		}
		j++;
	}
	return 1;	
}	
