    int ans = 0;
    for ( int i = n; i >= 1; i --  )
    {
        for ( int j = 0; j < i; j ++ )
        {
            if ( ! ( ( sum[i] - sum[j] ) % k ) )
            {
                ans ++;
            } 
        }
    }
    printf("%d\n",ans);