
	sort(v.begin(), v.end(), cmp);

	int result = 0;
	
	for(int i = 0; i < m; ++i)
	{
		int start = v[i].first.first;
		int end = v[i].first.second;
		int boxCount = 0;

		for(int search = start; search < end; ++search)
			boxCount = max(boxCount, load[search]);

		boxCount = min(v[i].second, c - boxCount);
		result += boxCount;

		for(int search = start; search < end; ++search)
			load[search] += boxCount;
	}

	cout << result << endl;
}
