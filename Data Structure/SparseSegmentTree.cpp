// Cuando el rango (0, n - 1) es muy largo y sea muy pesado guardar un arreglo de tamanio n * 4 
// se puede utilizar un Sparse S. T., el cual usa punteros para los 2 hijos de cada nodo, siendo creados
// solo cuando se necesitan

const int SZ = 1<<17;

template<class T> struct node {
	T val = 0; node<T>* c[2];
	node() { c[0] = c[1] = NULL; }
	void upd(int ind, T v, int L = 0, int R = SZ-1) { // add v
		if (L == ind && R == ind) { val += v; return; }
		int M = (L+R)/2;
		if (ind <= M) {
			if (!c[0]) c[0] = new node();
			c[0]->upd(ind,v,L,M);
		} else {
			if (!c[1]) c[1] = new node();
			c[1]->upd(ind,v,M+1,R);
		}
		val = 0; F0R(i,2) if (c[i]) val += c[i]->val;
	}
	T query(int lo, int hi, int L = 0, int R = SZ-1) { // query sum of segment
		if (hi < L || R < lo) return 0;
		if (lo <= L && R <= hi) return val;
		int M = (L+R)/2; T res = 0;
		if (c[0]) res += c[0]->query(lo,hi,L,M);
		if (c[1]) res += c[1]->query(lo,hi,M+1,R);
		return res;
	}
};
