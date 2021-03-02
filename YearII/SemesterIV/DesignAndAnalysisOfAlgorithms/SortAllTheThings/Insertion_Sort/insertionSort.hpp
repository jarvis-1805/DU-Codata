class Insertion_Sort
{
    public:
        int insertion_sort(int *, int);

};

int Insertion_Sort::insertion_sort(int *array, int n)
{
    int i, j, totalComp = 0;
    for(i=1; i<n; i++)
    {
        int key = array[i];
        int ctr = 0;

        for(j=i-1; j>=0; j--)
        {
            ctr++;
            totalComp++;
            if(key < array[j])
                array[j+1] = array[j];
            else
                break;
        }
        array[j+1] = key;
    }

    return totalComp;
}