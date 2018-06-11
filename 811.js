/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    let obj = {};
    let response = [];
    for (let str in cpdomains) {
        let tmp = str.split(" ");
        let num = parseInt(tmp[0]);
        let domain = tmp[1].split(".");
        let key = domain.pop();
        obj[key] = obj[key] ? obj[key] + num : num;
        
        while (domain.length > 0) {
            key = domain.pop() + "." + key;
            obj[key] = obj[key] ? obj[key] + num : num;
        }
    }
    for (let i in obj) {
        response.push(obj[i] + " " + i);
    }
    return response;
};