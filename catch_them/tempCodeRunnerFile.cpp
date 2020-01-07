        printf("///////////\n");
        map<int, int>::iterator ite;
        for ( ite = m.begin(); ite != m.end(); ite ++ )
        {
            cout << ite -> first << ' ' << ite -> second<<endl;
        }
        printf("///////////\n");