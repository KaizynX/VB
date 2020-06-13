#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
#define int unsigned
#define push_back emplace_back
// #define MULTI_THREAD

const int N = 560010;
const int THREAD_COUNT = 1;

struct Timer{
	double start,pre;
	Timer(){start=pre=clock();}
	void operator()(const string &s){
		double now=clock();
		cerr<<"["<<s<<"] ";
		cerr<<"Interval: "<<(now-pre)/1000<<"s | ";
		cerr<<"Total:"<<(now-start)/1000<<"s"<<endl;
		pre=now;
	}
}timer;

struct Info
{
	int start;
	int end;
};

namespace bkt{
	const int null=N-1;
	struct element{
		int pre,nxt;
	}bkt[N];
	int head[N],top;
	void add(int i,int deg){
		int &h=head[deg];
		bkt[i]={null,h};
		bkt[h].pre=i;
		h=i;
	}
	void erase(int i,int deg){
		bkt[bkt[i].pre].nxt=bkt[i].nxt;
		bkt[bkt[i].nxt].pre=bkt[i].pre;
		if(i==head[deg])head[deg]=bkt[i].nxt;
	}
}

namespace DISC {
#define u32 unsigned
#define re register
	typedef pair<int, int> pii;
	u32 a[N], b[N], *c;
	int cnt0[1 << 8], cnt8[1 << 8], cnt16[1 << 8], cnt24[1 << 8];
	int n, m, part;
	pii arg[THREAD_COUNT];

	inline void sort() {
		for (int re i = 1; i < 256; ++i) {
			cnt0[i] += cnt0[i - 1];
			cnt8[i] += cnt8[i - 1];
			cnt16[i] += cnt16[i - 1];
			cnt24[i] += cnt24[i - 1];
		}

		re int rep = n >> 3, tim = rep;
		re u32 *now = a + n - 1;
		while (tim--) {
			b[--cnt0[now[0] & 255]] = now[0];
			b[--cnt0[now[-1] & 255]] = now[-1];
			b[--cnt0[now[-2] & 255]] = now[-2];
			b[--cnt0[now[-3] & 255]] = now[-3];
			b[--cnt0[now[-4] & 255]] = now[-4];
			b[--cnt0[now[-5] & 255]] = now[-5];
			b[--cnt0[now[-6] & 255]] = now[-6];
			b[--cnt0[now[-7] & 255]] = now[-7]; now -= 8;
		}
		switch (n & 7) {
		case 7: {b[--cnt0[*now & 255]] = *now; --now; }
		case 6: {b[--cnt0[*now & 255]] = *now; --now; }
		case 5: {b[--cnt0[*now & 255]] = *now; --now; }
		case 4: {b[--cnt0[*now & 255]] = *now; --now; }
		case 3: {b[--cnt0[*now & 255]] = *now; --now; }
		case 2: {b[--cnt0[*now & 255]] = *now; --now; }
		case 1: {b[--cnt0[*now & 255]] = *now; --now; }
		}
		tim = rep;
		now = b + n - 1;
		while (tim--) {
			a[--cnt8[now[0] >> 8 & 255]] = now[0];
			a[--cnt8[now[-1] >> 8 & 255]] = now[-1];
			a[--cnt8[now[-2] >> 8 & 255]] = now[-2];
			a[--cnt8[now[-3] >> 8 & 255]] = now[-3];
			a[--cnt8[now[-4] >> 8 & 255]] = now[-4];
			a[--cnt8[now[-5] >> 8 & 255]] = now[-5];
			a[--cnt8[now[-6] >> 8 & 255]] = now[-6];
			a[--cnt8[now[-7] >> 8 & 255]] = now[-7]; now -= 8;
		}
		switch (n & 7) {
		case 7: {a[--cnt8[*now >> 8 & 255]] = *now; --now; }
		case 6: {a[--cnt8[*now >> 8 & 255]] = *now; --now; }
		case 5: {a[--cnt8[*now >> 8 & 255]] = *now; --now; }
		case 4: {a[--cnt8[*now >> 8 & 255]] = *now; --now; }
		case 3: {a[--cnt8[*now >> 8 & 255]] = *now; --now; }
		case 2: {a[--cnt8[*now >> 8 & 255]] = *now; --now; }
		case 1: {a[--cnt8[*now >> 8 & 255]] = *now; --now; }
		}
		tim = rep;
		now = a + n - 1;
		while (tim--) {
			b[--cnt16[now[0] >> 16 & 255]] = now[0];
			b[--cnt16[now[-1] >> 16 & 255]] = now[-1];
			b[--cnt16[now[-2] >> 16 & 255]] = now[-2];
			b[--cnt16[now[-3] >> 16 & 255]] = now[-3];
			b[--cnt16[now[-4] >> 16 & 255]] = now[-4];
			b[--cnt16[now[-5] >> 16 & 255]] = now[-5];
			b[--cnt16[now[-6] >> 16 & 255]] = now[-6];
			b[--cnt16[now[-7] >> 16 & 255]] = now[-7]; now -= 8;
		}
		switch (n & 7) {
		case 7: {b[--cnt16[*now >> 16 & 255]] = *now; --now; }
		case 6: {b[--cnt16[*now >> 16 & 255]] = *now; --now; }
		case 5: {b[--cnt16[*now >> 16 & 255]] = *now; --now; }
		case 4: {b[--cnt16[*now >> 16 & 255]] = *now; --now; }
		case 3: {b[--cnt16[*now >> 16 & 255]] = *now; --now; }
		case 2: {b[--cnt16[*now >> 16 & 255]] = *now; --now; }
		case 1: {b[--cnt16[*now >> 16 & 255]] = *now; --now; }
		}
		tim = rep;
		now = b + n - 1;
		while (tim--) {
			a[--cnt24[now[0] >> 24]] = now[0];
			a[--cnt24[now[-1] >> 24]] = now[-1];
			a[--cnt24[now[-2] >> 24]] = now[-2];
			a[--cnt24[now[-3] >> 24]] = now[-3];
			a[--cnt24[now[-4] >> 24]] = now[-4];
			a[--cnt24[now[-5] >> 24]] = now[-5];
			a[--cnt24[now[-6] >> 24]] = now[-6];
			a[--cnt24[now[-7] >> 24]] = now[-7]; now -= 8;
		}
		switch (n & 7) {
		case 7: {a[--cnt24[*now >> 24]] = *now; --now; }
		case 6: {a[--cnt24[*now >> 24]] = *now; --now; }
		case 5: {a[--cnt24[*now >> 24]] = *now; --now; }
		case 4: {a[--cnt24[*now >> 24]] = *now; --now; }
		case 3: {a[--cnt24[*now >> 24]] = *now; --now; }
		case 2: {a[--cnt24[*now >> 24]] = *now; --now; }
		case 1: {a[--cnt24[*now >> 24]] = *now; --now; }
		}
	}

	inline void* disc(void *_arg) {
		Info arg = *(Info*)_arg;
		for (u32 *it = c + arg.start, *ed = c + arg.end; it < ed; ++it) {
			*it = lower_bound(a, a + m, *it) - a;
		}
	}
	
	inline int init(u32 *_c, const int &_n) {
		c = _c;
		n = _n;
		memcpy(a, c, sizeof(u32)*n);
		/************* init_data ******************/
		for (u32 re *to = a + n, *now = a; now < to; ++now) {
			++cnt0[*now & 255];
			++cnt8[*now >> 8 & 255];
			++cnt16[*now >> 16 & 255];
			++cnt24[*now >> 24 & 255];
		}
		/************* init_data ******************/
		sort();
		m = unique(a, a + n) - a;
#ifndef MULTI_THREAD
		for (u32 *it = c, *ed = c+n; it < ed; ++it) {
			*it = lower_bound(a, a + m, *it) - a;
		}
#else
		part = n / THREAD_COUNT;
		pthread_attr_t attr;
		void *status;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
		Info info[THREAD_COUNT];
		pthread_t threads[THREAD_COUNT];
		for (re int i = 0; i < THREAD_COUNT; ++i) {
			info[i].start = i * part, info[i].end = i * part + part;
		}
		info[THREAD_COUNT-1].end = n;
		for (re int i = 0; i < THREAD_COUNT; ++i) {
			int rc = pthread_create(&threads[i], NULL, disc, (void*)&(info[i]));
			if (rc) cerr << "Wrong!" << endl;
		}
		pthread_attr_destroy(&attr);
		for (re int i = 0; i < THREAD_COUNT; ++i) {
			int rc = pthread_join(threads[i], &status);
			if (rc) cerr << "Wrong!" << endl;
		}
#endif
		return m;
	}
#undef u32
#undef re
}

namespace Solve{
typedef pair<int,int> pii;
// vector<int> a[N],b[N];
int s, n;
set<pii> order;
int in_deg[N],ot_deg[N],deg[N];
int dis_b[N],dcnt_b[N],dcnt;
int dis_a[N],dcnt_a[N];
bool del[N],vis[N],inq[N];
vector<int> rec;
vector<vector<int>> ans;

const int null = N-1;
struct EDGE {
	struct element {
		int val, pre, nxt;
	} p[N<<1];
	int tot = N;
	EDGE() {
		for (int i = 0; i < N; ++i) p[i].nxt = null;
	}
	void insert(const int &x, const int &y) {
		++tot;
		p[tot] = {y, x, p[x].nxt};
		p[p[x].nxt].pre = tot;
		p[x].nxt = tot;
	}
	void erase(const int &x) {
		p[p[x].pre].nxt = p[x].nxt;
		p[p[x].nxt].pre = p[x].pre;
	}
	int get_next(const int &x) {
		int y = p[x].nxt, z;
		while (y != null && del[p[y].val]) {
			z = p[y].nxt;
			erase(y);
			y = z;
		}
		return y;
	}
} a, b;

void dfs(const int&);
void bfs_a3();
void bfs_b7();
void* multi_thread_rotate(void *);
inline void adjust();
inline void topo();
vector<vector<int>>& solve(const int*, const int &, const int&);

void dfs(const int &x){
	vis[x]=1;
	// for(const auto &p:a[x])
	for (int i=a.get_next(x),p;i!=null;i=a.get_next(i)){
		p=a.p[i].val;
		if(p==s){
			if(rec.size()>=3)ans.push_back(rec);
		} else if(!vis[p] && dcnt_b[p]==dcnt){
			rec.push_back(p);
			if(rec.size()+dis_b[p]<=8)dfs(p);
			rec.pop_back();
		}
	}
	vis[x]=0;
}
void bfs_a3(){
	static queue<int> q;
	q.push(s);
	dcnt_a[s]=dcnt; dis_a[s]=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		// for(const auto &p:a[x])
		for (int i=a.get_next(x),p;i!=null;i=a.get_next(i)){
			p=a.p[i].val;
			if(dcnt_a[p]!=dcnt && !del[p]){
				dcnt_a[p]=dcnt;
				dis_a[p]=dis_a[x]+1;
				if(dis_a[p]<3)q.push(p);
			}
		}
	}
}
void bfs_b7(){
	static queue<int> q;
	q.push(s);
	dcnt_b[s]=dcnt; dis_b[s]=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		// for(const auto &p:b[x])
		for (int i=b.get_next(x),p;i!=null;i=b.get_next(i)){
			p=b.p[i].val;
			if(dcnt_b[p]!=dcnt && !del[p]){
				dcnt_b[p]=dcnt;
				dis_b[p]=dis_b[x]+1;
				if(/*dis_b[p]<7*/ dis_b[p]<4 || (dcnt_a[p]==dcnt && dis_b[p]+dis_a[p]<=7))q.push(p);
			}
		}
	}
}
vector<vector<int>>& solve(const int *eset, const int &sz, const int &_n){
	ans.reserve(3000000);
	for(int i=0;i<sz;i+=2){
		// a[eset[i]].push_back(eset[i^1]);
		// b[eset[i^1]].push_back(eset[i]);
		a.insert(eset[i], eset[i^1]);
		b.insert(eset[i^1], eset[i]);
		++ot_deg[eset[i]];
		++in_deg[eset[i^1]];
	}
	n=_n;
	static queue<int> q;
	topo();

	fill(bkt::head,bkt::head+N,bkt::null);
	for(int i=0;i<n;i++)
	if(!del[i]){
		deg[i]=in_deg[i]+ot_deg[i];
		bkt::add(i,deg[i]);
	}

	bkt::top=N-2;
	while(1){
		while(bkt::top!=0 && bkt::head[bkt::top]==bkt::null)bkt::top--;
		if(bkt::top==0)break;
		
		s=bkt::head[bkt::top];
		
		dcnt++;
		bfs_a3();
		bfs_b7();
		rec.assign(1,s);
		dfs(s);
		del[s]=1;
		
		q.push(s);
		inq[s]=1;
		while(q.size()){
			int x=q.front();q.pop();
			// for(const int &p:a[x])if(!del[p]){
			for (int i=a.get_next(x),p;i!=null;i=a.get_next(i)){
				p=a.p[i].val;
				bkt::erase(p,deg[p]);
				deg[p]--;
				bkt::add(p,deg[p]);
				if(--in_deg[p]==0 && !inq[p]){
					q.push(p);
					inq[p]=1;
				}
			}
			// for(const int &p:b[x])if(!del[p]){
			for (int i=b.get_next(x),p;i!=null;i=b.get_next(i)){
				p=b.p[i].val;
				bkt::erase(p,deg[p]);
				deg[p]--;
				bkt::add(p,deg[p]);
				if(--ot_deg[p]==0 && !inq[p]){
					q.push(p);
					inq[p]=1;
				}
			}
			bkt::erase(x,deg[x]);
			del[x]=1;
			deg[x]=in_deg[x]=ot_deg[x]=0;
			inq[x]=0;
		}
	}
	adjust();
	return ans;
}
void* multi_thread_rotate(void *_arg) {
	Info arg = *(Info*)_arg;
	for (int i = arg.start; i < arg.end; ++i) {
		vector<int> &arr = ans[i];
		rotate(arr.begin(),min_element(arr.begin(),arr.end()),arr.end());
	}
}
void adjust(){ //把环里的最小值转到最前并排序
#ifndef MULTI_THREAD
	for(auto &arr:ans){
		rotate(arr.begin(),min_element(arr.begin(),arr.end()),arr.end());
	}
#else
	int sz = ans.size(), part = sz/THREAD_COUNT;
	pthread_attr_t attr;
	void *status;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	Info info[THREAD_COUNT];
	pthread_t threads[THREAD_COUNT];
	for (int i = 0; i < THREAD_COUNT; ++i) {
		info[i].start = i * part, info[i].end = i * part + part;
	}
	info[THREAD_COUNT-1].end = sz;
	for (int i = 0; i < THREAD_COUNT; ++i) {
		int rc = pthread_create(&threads[i], NULL, multi_thread_rotate, (void*)&(info[i]));
		if (rc) cerr << "Wrong!" << endl;
	}
	pthread_attr_destroy(&attr);
	for (int i = 0; i < THREAD_COUNT; ++i) {
		int rc = pthread_join(threads[i], &status);
		if (rc) cerr << "Wrong!" << endl;
	}
#endif
	sort(ans.begin(),ans.end(),[](const vector<int> &a,const vector<int> &b)->bool{
		if(a.size()!=b.size())return a.size()<b.size();
		return a<b;
	});
}
inline void topo(){
	static queue<int> q;
	for(int i=0;i<n;++i){
		if(in_deg[i]==0 || ot_deg[i]==0){
			q.push(i);
			inq[i]=1;
		}
	}
	while(q.size()){
		int x=q.front();q.pop();
		// for(const int &p:a[x])if(!del[p]){
		for (int i=a.get_next(x),p;i!=null;i=a.get_next(i)){
			p=a.p[i].val;
			if(--in_deg[p]==0 && !inq[p]){
				q.push(p);
				inq[p]=1;
			}
		}	
		// for(const int &p:b[x])if(!del[p]){
		for (int i=b.get_next(x),p;i!=null;i=b.get_next(i)){
			p=b.p[i].val;
			if(--ot_deg[p]==0 && !inq[p]){
				q.push(p);
				inq[p]=1;
			}
		}
		del[x]=1;
		in_deg[x]=ot_deg[x]=0;
		inq[x]=0;
	}
}

}

int eset[N], n = 0;

inline void input(){ //����eset
	freopen("test_data2.txt","r",stdin);
	// freopen("sample_data.txt","r",stdin);
	int x,y,z;
	while(~scanf("%u,%u,%u",&x,&y,&z))
		eset[n++]=x,eset[n++]=y;
}

void output(const vector<vector<int>> &ans){ //���ans
	freopen("output.txt","w",stdout);
	printf("%u\n",(int)ans.size());
	for(const auto &arr:ans)
	for(int j=0;j<arr.size();j++)
		printf("%u%c",DISC::a[arr[j]],",\n"[j==arr.size()-1]);
}


signed main(){
	input();
	int m=DISC::init(eset, n);
	vector<vector<int>> &ans=Solve::solve(eset,n,m);
	output(ans);
	
	timer("");
	return 0;
}
