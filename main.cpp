#include <bits/stdc++.h>
// Add to P
P = addPoly(P, numer);
}


// Trim trailing zeros
while (P.size() > 1 && P.back() == Rat(0)) P.pop_back();


int degree = (int)P.size() - 1;
if (degree != k - 1) {
cerr << "Note: reconstructed degree = " << degree << " (expected " << (k - 1) << ")\n";
}


// -------- Verify against ALL provided points, if present --------
bool ok = true;
for (auto& kv : j.items()) {
if (kv.key() == "keys") continue;
int x = stoi(kv.key());
int base = stoi(kv.value().at("base").get<string>());
string vstr = kv.value().at("value").get<string>();
cpp_int y = fromBase(vstr, base);


Rat val = evalAt(P, cpp_int(x));
if (val.denominator() != 1 || val.numerator() != y) {
ok = false;
cerr << "Mismatch at x=" << x << ": got " << ratToString(val)
<< " expected " << y << "\n";
}
}


// -------- Output --------
cout << "k = " << k << ", degree m = " << (k - 1) << "\n";
cout << "Polynomial coefficients (highest degree -> constant):\n";
for (int i = (int)P.size() - 1; i >= 0; --i) {
cout << "a[" << i << "] = " << ratToString(P[i]) << (i ? ", " : "\n");
}
cout << "Verification on all given points: " << (ok ? "PASS" : "FAIL") << "\n";


return ok ? 0 : 2;


} catch (const exception& e) {
cerr << "Error: " << e.what() << "\n";
return 1;
}
}
