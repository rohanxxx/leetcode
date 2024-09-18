/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    // Helper function to extract the hostname from the URL
string getHostname(string url) {
    int pos = min(url.size(), url.find('/', 7));
    cout << "url.size(): " << url.size() << endl;
    cout << "pos: " << pos << endl;
    return url.substr(7, pos - 7);
}

// Depth-First Search (DFS) function to crawl the URLs
void dfs(string url, string startHostname, unordered_set<string> &visited, HtmlParser &htmlParser) {
    visited.insert(url);
    for (string nextUrl : htmlParser.getUrls(url)) {
        if (getHostname(nextUrl) == startHostname && !visited.count(nextUrl)) {
            dfs(nextUrl, startHostname, visited, htmlParser);
        }
    }
}

// Main function to crawl URLs
vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    string startHostname = getHostname(startUrl);
    cout << "startHostName: " << startHostname << endl;
    unordered_set<string> visited;
    dfs(startUrl, startHostname, visited, htmlParser);
    return vector<string>(visited.begin(), visited.end());
}
};