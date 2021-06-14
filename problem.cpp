using namespace std;

long long int merge(int *v, int l, int m, int r) {

	
	int i, j, k, left_size, right_size;
   long long int ans=0;
	
	
   left_size = m-l+1; right_size = r-m;

   int larr[left_size], rarr[right_size];


   for(i = 0; i<left_size; i++)
      larr[i] = v[l+i];
   for(j = 0; j<right_size; j++)
      rarr[j] = v[m+1+j];
   i = 0; j = 0; k = l;


	for (k=l; i<left_size && j<right_size; k++) {
      if(larr[i] <= rarr[j])	
			v[k] = larr[i++];      
		else{
         v[k] = rarr[j++];
			ans += sizeof(larr)/sizeof(larr[0])-i; 
      }

   }
   while(i<left_size) {      
      v[k] = larr[i];
      i++; k++;
   }
   while(j<right_size) {     
      v[k] = rarr[j];
      j++; k++;
   }

	return ans;

}

long long int merge_sort (int *v, int l, int r) {
	long long int ans=0;
	if (l<r) {
		int m = (l+r)/2;
		ans+=merge_sort(v,l,m);
		ans+=merge_sort(v, m+1,r);
		ans+=merge(v,l,m,r);
	}
	return ans;
}

int main () {
	
	int n;
	cin >> n;
	int v[n];

	for (int a=0; a<n; a++) {
		cin >> v[a];
	}
	long long int ans = merge_sort(v,0,n-1);
	cout << ans << endl;
	return 0;
} 
