#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<int>::iterator vintit;
typedef vector<vector<int> >::iterator vvintit;

void pretty_print (vvint &all_combs){
    int cnt = 1;
    for (vvintit vvi = all_combs.begin () ; vvi != all_combs.end () ; vvi++){
        cout << "Combination #" << cnt << ": [ ";
        for (vintit vi = vvi->begin () ; vi != vvi->end () ; vi++){
            cout << *vi << " ";
        }
        cout << "]" << endl;
        cnt++;
    }
}

void push_combinations (vvint &all_combs, vint &curr_comb, int offset, int n, int kk){
    // Recursive call
    if (kk == 0){
        all_combs.push_back (curr_comb);
        return;
    }

    else{
        for (int i = offset + 1 ; i <= n - kk + 1; i++){
            curr_comb.push_back (i);
            push_combinations (all_combs, curr_comb, i, n, kk - 1);
            curr_comb.pop_back ();
        }
    }

    return;
}

vvint all_combinations (int n, int k){
    // Given integers 1..n, return all combinations of k integers.
    vvint all_combs;
    vint curr_comb;

    if (n < k || n < 0 || k < 0){
        return all_combs;   // Return empty vector if input invalid
    }

    else{
        push_combinations (all_combs, curr_comb, 0, n, k);
    }

    return all_combs;
}


int main (int argc, char *argv[]){
    int n, k;
    vvint all_combs;

    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;

    all_combs = all_combinations (n, k);

    cout << "Print all combinations (" << n << ", " << k << "):" << endl;

    pretty_print (all_combs);

    return 0;
}
