let utilites = {
 updateItemList: <T extends Record<string, any>>(list: Array<T>, item: T, action: 'ADD' | 'DELETE' | 'UPDATE' | 'PUT', key: keyof T = 'id'): typeof list => {
        list = list || [];
        let newList = list.slice();
        let itemIndex;
        if (action === 'UPDATE') {
            newList = newList.map((x => x[key] === item[key] ? item : x));
            // itemIndex = newList.findIndex(listItem => item[key] === listItem[key]);
            // if (itemIndex !== -1)
            //     newList.splice(itemIndex, 1, item);
            return newList;
        } else if (action === 'ADD') {
            newList.unshift(item);
            return newList;
        } else if (action === 'DELETE') {
            return newList.filter(listItem => item[key] !== listItem[key]);
        }
        else if (action === 'PUT') {
            itemIndex = newList.findIndex(listItem => item[key] === listItem[key]);
            if (itemIndex !== -1)
                newList.splice(itemIndex, 1, item);
            else {
                newList.push(item);
            }
            return newList;
        }
        return newList;
    },
    capitalize: (text: string): string => (text[0]?.toUpperCase() || '') + text.slice(1),
    validateEmail: (email: string) => {
        let tester = /^[-!#$%&'*+\/0-9=?A-Z^_a-z{|}~](\.?[-!#$%&'*+\/0-9=?A-Z^_a-z`{|}~])*@[a-zA-Z0-9](-*\.?[a-zA-Z0-9])*\.[a-zA-Z](-?[a-zA-Z0-9])+$/;
        if (!email)
            return false;

        if (email.length > 254)
            return false;

        var valid = tester.test(email);
        if (!valid)
            return false;

        // Further checking of some things regex can't handle
        var parts = email.split("@");
        if (parts[0].length > 64)
            return false;

        var domainParts = parts[1].split(".");
        if (domainParts.some(function (part) { return part.length > 63; }))
            return false;

        return true
    },

    validateUrl: (uri: string): boolean => {
        let tester = /^(?:http(s)?:\/\/)?[\w.-]+(?:\.[\w\.-]+)+[\w\-\._~:/?#[\]@!\$&'\(\)\*\+,;=.]+$/;
        if (!uri) return false;
        return tester.test(uri);
    },
}
export default utilites;
