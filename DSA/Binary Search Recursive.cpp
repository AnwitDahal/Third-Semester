BinarySearch(A,l,r,key){
	if (l==r){
		if (key==A[1]){
			return l+1; 	//index starts from 0
		}
		else{
			return 0;
		}
	}
	else{
		m-(l+r)/2;
		if (key==A[m]){
			return m+1;
		}
		else if (key<A[m]){
			return BinarySearch(l,m-1,key);
		}
		else{
			return BinarySearch(m+1,r,key);
		}
	}
}
