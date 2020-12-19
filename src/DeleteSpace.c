char *DeleteSpace(char s[])
{
        char *str = (char *)malloc(strlen(s));
        int i, j = 0;
        for(i = 0; i<strlen(s);i++)
                if(s[i] != ' ') {
                        str[j] = s[i];
                        j++;
                }
        str[j] = 0;

        return str;
}

