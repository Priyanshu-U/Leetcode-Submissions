class TimeMap {
public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    time_map[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto itr = time_map.find(key);
    if (itr == time_map.end())
      return "";

    std::vector<std::pair<int, string>> &values = itr->second;
    int low = 0;
    int high = values.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (values[mid].first < timestamp)
        low = mid + 1;
      else if (values[mid].first > timestamp)
        high = mid - 1;
      else
        return values[mid].second;
    }

    return high >= 0 ? values[high].second : "";
  }

private:
  std::unordered_map<string, std::vector<std::pair<int, string>>> time_map;
}; 
