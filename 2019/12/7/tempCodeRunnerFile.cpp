int _len = strlen(ss), pos = 0;
    for ( int i = _len, j = _len; i <= _len * 2; i ++, j -- )
    {
        ss[i] = ss[j];
    }
    _len = strlen(ss);
    if ( k % _len == 0 ) pos = _len;
    else pos = k % _len;
    printf("%c\n",ss[pos]);
