function isOperator(o) {
    return (o === '+' || o === '-' || o === '*' || o === '/' || o === '^');
}

function isValidChar(c) {
    return (/\d/.test(c) || isOperator(c) || c === '(' || c === ')' || c === ' ' || c === '.');
}

function Bracket_Matching(s) {
    let inCount = 0, outCount = 0;
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === '(') {
            inCount++;
        }
        if (s[i] === ')') {
            outCount++;
        }
    }
    return inCount === outCount;
}

function Priority(o) {
    if (o === '+' || o === '-') return 1;
    if (o === '*' || o === '/') return 2;
    if (o === '^') return 3;
    return 0;
}

function isValid(s) {
    if (!Bracket_Matching(s)) return false;
    let num = 0;
    if (s.includes("**") || s.includes("//")) return false;
    for (let i = 0; i < s.length; ++i) {
        if (s[0] === ')') return false;
        if (!isValidChar(s[i])) return false;
        if (s[i] === '(' && s[i + 1] === ')') return false;
        if (/\d/.test(s[i])) {
            num++;
        }
    }
    return num > 0;
}

function Normalize(s) {
    let res = s.split(/\s+/).join(' ');
    
    while (res.includes('---')) {
        res = res.replace('---', '-');
    }
    while (res.includes('--')) {
        res = res.replace('--', '+');
    }

    while (res.includes('++')) {
        res = res.replace('++', '+');
    }
    
    while (res[0] === '+') {
        res = res.replace('+', '');
    }

    return res;
}

function RPN(s) {
    s = Normalize(s);
    let st = [];
    let postfix = '';
    
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === '-' && (i === 0 || s[i - 1] === '(' || isOperator(s[i - 1]))) {
            let ss = "-";
            i++;
            while (i < s.length && (/\d/.test(s[i]) || s[i] === '.')) {
                ss += s[i];
                i++;
            }
            postfix += ss + " ";
            i--;
        } else if (/\d/.test(s[i]) || s[i] === '.') {
            let ss = "";
            while (i < s.length && (/\d/.test(s[i]) || s[i] === '.')) {
                ss += s[i];
                i++;
            }
            postfix += ss + " ";
            i--;
        } else if (s[i] === '(') {
            st.push(s[i]);
        } else if (s[i] === ')') {
            while (st.length && st[st.length - 1] !== '(') {
                postfix += st.pop() + " ";
            }
            st.pop();
        } else if (isOperator(s[i])) {
            while (st.length && Priority(st[st.length - 1]) >= Priority(s[i])) {
                postfix += st.pop() + " ";
            }
            st.push(s[i]);
        }
    }

    while (st.length) {
        postfix += st.pop() + " ";
    }
    
    return postfix;
    
}

function calculate(s) {
    let st = [];
    
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === ' ') continue;
        
        let ss = '';
        if (s[i] === '-' && /\d/.test(s[i + 1])) {
            ss += "-";
            i++;
        }
        while (i < s.length && (/\d/.test(s[i]) || s[i] === '.')) {
            ss += s[i];
            i++;
        }
        if (ss) {
            st.push(parseFloat(ss));
            i--;
        }
        
        if (isOperator(s[i])) {
            let x = st.pop();
            let y = st.pop();

            switch (s[i]) {
                case '+': st.push(y + x); break;
                case '-': st.push(y - x); break;
                case '*': st.push(y * x); break;
                case '/': st.push(y / x); break;
                case '^': st.push(Math.pow(y, x)); break;
            }
        }
    }
    return st[st.length - 1];
}

function cal() {
    let expression = document.getElementById('display').value;
    if (isValid(expression)) {
        let rpn = RPN(expression); 
        let result = calculate(rpn); 
        if (!isNaN(result)) {
            document.getElementById('display').value = result;
        } else {
            document.getElementById('display').value = "Invalid!";
        }
    }
    else {
        document.getElementById('display').value = "Invalid!";
    }
}

function PUSH(value) {
    document.getElementById('display').value += value;
}

function clearScreen() {
    document.getElementById('display').value = ''; 
}

document.addEventListener('keydown', function(event) {
    const display = document.getElementById('display');
    
    const validKeys = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '/', '*', '-', '+', '^', '(', ')'];
    
    if (validKeys.includes(event.key)) {
        display.value += event.key;
    }
    
    if (event.key === 'Enter') {
        cal();
    }
    if (event.key === 'Backspace') {
        display.value = display.value.slice(0, -1);
    }

    if (event.key === 'Escape') {
        clearScreen(); 
    }
});
