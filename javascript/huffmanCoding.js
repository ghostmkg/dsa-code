/**
 * Huffman Coding Algorithm
 * 
 * Description: Greedy algorithm for lossless data compression. Assigns variable-length
 * codes to characters based on their frequencies, with shorter codes for more frequent
 * characters.
 * 
 * Time Complexity: O(n log n) where n is number of unique characters
 * Space Complexity: O(n)
 * 
 * Use Cases:
 * - File compression (ZIP, GZIP)
 * - Image compression (JPEG)
 * - Network data transmission
 * - Multimedia codecs
 * 
 * Example:
 * Input: text = "hello"
 * Output: {codes: {h:'10', e:'11', l:'0', o:'110'}, compressed: '1011000110'}
 */

class HuffmanNode {
    constructor(char, freq, left = null, right = null) {
        this.char = char;
        this.freq = freq;
        this.left = left;
        this.right = right;
    }

    isLeaf() {
        return this.left === null && this.right === null;
    }
}

class MinHeap {
    constructor() {
        this.heap = [];
    }

    push(node) {
        this.heap.push(node);
        this.bubbleUp(this.heap.length - 1);
    }

    pop() {
        if (this.heap.length === 0) return null;
        if (this.heap.length === 1) return this.heap.pop();

        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        return min;
    }

    bubbleUp(index) {
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            if (this.heap[index].freq >= this.heap[parentIndex].freq) break;
            [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
            index = parentIndex;
        }
    }

    bubbleDown(index) {
        while (true) {
            let smallest = index;
            const left = 2 * index + 1;
            const right = 2 * index + 2;

            if (left < this.heap.length && this.heap[left].freq < this.heap[smallest].freq) {
                smallest = left;
            }
            if (right < this.heap.length && this.heap[right].freq < this.heap[smallest].freq) {
                smallest = right;
            }
            if (smallest === index) break;

            [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
            index = smallest;
        }
    }

    size() {
        return this.heap.length;
    }
}

function huffmanCoding(text) {
    // Input validation
    if (typeof text !== 'string' || text.length === 0) {
        throw new Error('Invalid input: text must be a non-empty string');
    }

    // Calculate character frequencies
    const freqMap = new Map();
    for (let char of text) {
        freqMap.set(char, (freqMap.get(char) || 0) + 1);
    }

    // Special case: single unique character
    if (freqMap.size === 1) {
        const char = Array.from(freqMap.keys())[0];
        return {
            codes: { [char]: '0' },
            tree: new HuffmanNode(char, text.length),
            compressed: '0'.repeat(text.length),
            original: text,
            compressionRatio: calculateCompressionRatio(text, '0'.repeat(text.length))
        };
    }

    // Build Huffman tree
    const minHeap = new MinHeap();
    for (let [char, freq] of freqMap) {
        minHeap.push(new HuffmanNode(char, freq));
    }

    while (minHeap.size() > 1) {
        const left = minHeap.pop();
        const right = minHeap.pop();
        const parent = new HuffmanNode(null, left.freq + right.freq, left, right);
        minHeap.push(parent);
    }

    const root = minHeap.pop();

    // Generate codes
    const codes = {};
    function generateCodes(node, code = '') {
        if (node.isLeaf()) {
            codes[node.char] = code || '0';
            return;
        }
        if (node.left) generateCodes(node.left, code + '0');
        if (node.right) generateCodes(node.right, code + '1');
    }
    generateCodes(root);

    // Compress text
    const compressed = text.split('').map(char => codes[char]).join('');

    return {
        codes,
        tree: root,
        compressed,
        original: text,
        compressionRatio: calculateCompressionRatio(text, compressed)
    };
}

function calculateCompressionRatio(original, compressed) {
    const originalBits = original.length * 8; // ASCII
    const compressedBits = compressed.length;
    const ratio = ((1 - compressedBits / originalBits) * 100).toFixed(2);
    return {
        originalBits,
        compressedBits,
        ratio: ratio + '%',
        savings: originalBits - compressedBits
    };
}

// Decode compressed text
function huffmanDecode(compressed, tree) {
    if (!compressed || !tree) {
        throw new Error('Invalid input for decoding');
    }

    // Special case: single character
    if (tree.isLeaf()) {
        return tree.char.repeat(compressed.length);
    }

    let decoded = '';
    let current = tree;

    for (let bit of compressed) {
        current = bit === '0' ? current.left : current.right;

        if (current.isLeaf()) {
            decoded += current.char;
            current = tree;
        }
    }

    return decoded;
}

// Encode with header (for self-contained compression)
function huffmanEncode(text) {
    const result = huffmanCoding(text);
    
    // Create header with frequency table
    const header = {};
    for (let char of text) {
        header[char] = (header[char] || 0) + 1;
    }

    return {
        header,
        compressed: result.compressed,
        codes: result.codes,
        compressionRatio: result.compressionRatio
    };
}

// Decode from encoded data
function huffmanDecodeFromHeader(encoded) {
    const { header, compressed } = encoded;

    // Rebuild Huffman tree from header
    const minHeap = new MinHeap();
    for (let [char, freq] of Object.entries(header)) {
        minHeap.push(new HuffmanNode(char, freq));
    }

    while (minHeap.size() > 1) {
        const left = minHeap.pop();
        const right = minHeap.pop();
        minHeap.push(new HuffmanNode(null, left.freq + right.freq, left, right));
    }

    const tree = minHeap.pop();
    return huffmanDecode(compressed, tree);
}

// Visualize Huffman tree
function visualizeTree(node, prefix = '', isLeft = true) {
    if (!node) return;

    console.log(prefix + (isLeft ? '├── ' : '└── ') + 
                (node.char || 'Internal') + ` (${node.freq})`);

    if (node.left || node.right) {
        if (node.left) {
            visualizeTree(node.left, prefix + (isLeft ? '│   ' : '    '), true);
        }
        if (node.right) {
            visualizeTree(node.right, prefix + (isLeft ? '│   ' : '    '), false);
        }
    }
}

// Get average code length
function getAverageCodeLength(codes, freqMap) {
    let totalLength = 0;
    let totalChars = 0;

    for (let [char, freq] of freqMap) {
        totalLength += codes[char].length * freq;
        totalChars += freq;
    }

    return (totalLength / totalChars).toFixed(2);
}

// Compare with fixed-length encoding
function compareEncodings(text) {
    const result = huffmanCoding(text);
    const uniqueChars = new Set(text).size;
    const fixedLength = Math.ceil(Math.log2(uniqueChars));
    const fixedBits = text.length * fixedLength;

    const freqMap = new Map();
    for (let char of text) {
        freqMap.set(char, (freqMap.get(char) || 0) + 1);
    }

    return {
        huffman: {
            bits: result.compressed.length,
            avgCodeLength: getAverageCodeLength(result.codes, freqMap)
        },
        fixed: {
            bits: fixedBits,
            codeLength: fixedLength
        },
        savings: fixedBits - result.compressed.length
    };
}

// Compress file content
function compressText(text) {
    const encoded = huffmanEncode(text);
    
    // Convert binary string to bytes (simulation)
    const bytes = [];
    for (let i = 0; i < encoded.compressed.length; i += 8) {
        const byte = encoded.compressed.slice(i, i + 8).padEnd(8, '0');
        bytes.push(parseInt(byte, 2));
    }

    return {
        header: encoded.header,
        bytes,
        originalSize: text.length,
        compressedSize: bytes.length,
        codes: encoded.codes
    };
}

// Decompress file content
function decompressText(compressed) {
    // Convert bytes back to binary string
    let binaryString = '';
    for (let byte of compressed.bytes) {
        binaryString += byte.toString(2).padStart(8, '0');
    }

    // Trim padding
    binaryString = binaryString.slice(0, compressed.originalSize * 8);

    return huffmanDecodeFromHeader({
        header: compressed.header,
        compressed: binaryString
    });
}

// Test cases
const text = "hello world! this is huffman coding example";

console.log('Original text:', text);
console.log('Length:', text.length, 'characters\n');

const result = huffmanCoding(text);
console.log('Huffman Codes:');
console.log(result.codes);

console.log('\nCompressed:', result.compressed);
console.log('Compression Ratio:', result.compressionRatio);

console.log('\nHuffman Tree:');
visualizeTree(result.tree);

const decoded = huffmanDecode(result.compressed, result.tree);
console.log('\nDecoded:', decoded);
console.log('Match:', decoded === text);

console.log('\nEncoding Comparison:');
console.log(compareEncodings(text));

// Test encode/decode cycle
const encoded = huffmanEncode(text);
const decodedFromHeader = huffmanDecodeFromHeader(encoded);
console.log('\nFull cycle test:', decodedFromHeader === text);

module.exports = { 
    huffmanCoding, 
    huffmanDecode, 
    huffmanEncode,
    huffmanDecodeFromHeader,
    visualizeTree,
    compareEncodings,
    compressText,
    decompressText
};
