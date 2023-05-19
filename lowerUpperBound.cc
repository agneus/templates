//lower_bound gets min value such that value >= target
//upper_bound gets min value such that value > target

vector<int> v;
//to get max value such that value <= target
auto it = upper_bound(v.begin(),v.end(), target);
if(it == v.begin()) return -1;
--it;
return it;

//to get max value such that value < target
auto it = lower_bound(v.begin(),v.end(), target);
if(it == v.begin()) return -1;
--it;
return it;

//the above is for vectors.
//you have upper and lower bounds with maps too
//for maps it looks kinda like this:
m.upper_bound(key)

