#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll t;
string a, b;

string Add(const string& a, const string& b) {
  if (a == "0" && b == "0") {
    return "0";
  }

  auto i = static_cast<ll>(a.length() - 1);
  auto j = static_cast<ll>(b.length() - 1);
  ll c = 0;

  auto oss = ostringstream{};

  while (0 <= i && 0 <= j) {
    auto v = a[i] - '0';
    auto w = b[j] - '0';

    auto x = v + w + c;
    if (x >= 2) {
      x -= 2;
      c = 1;
    } else {
      c = 0;
    }
    oss << x;

    --i;
    --j;
  }

  while (0 <= i) {
    auto v = a[i] - '0';

    auto x = v + c;
    if (x >= 2) {
      x -= 2;
      c = 1;
    } else {
      c = 0;
    }
    oss << x;

    --i;
  }

  while (0 <= j) {
    auto w = b[j] - '0';

    auto x = w + c;
    if (x >= 2) {
      x -= 2;
      c = 1;
    } else {
      c = 0;
    }
    oss << x;

    --j;
  }

  if (c == 1) {
    oss << c;
  }

  auto ans = oss.str();
  reverse(ans.begin(), ans.end());

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> a >> b;

    const auto& f = a.find_first_of('1');
    if (f != a.npos) {
      a = a.substr(f);
    } else {
      a = "0";
    }

    const auto& g = b.find_first_of('1');
    if (g != b.npos) {
      b = b.substr(g);
    } else {
      b = "0";
    }

    cout << Add(a, b) << '\n';
  }

  return 0;
}