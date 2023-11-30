import * as readline from 'node:readline'
import { stdin, stdout } from 'node:process'
import { readFileSync } from 'node:fs'
import { writeFileSync } from 'node:fs'
import { SchemaConverter }  from './public/json-schema-to-grammar.mjs'

function readChatMode() {
    const flagContent = readFileSync('ChatMode.flag', 'utf-8');
    const intValue = parseInt(flagContent.trim(), 10);
    return intValue;
}

async function setChatMode(Code) {
    writeFileSync('ChatMode.flag', Code.toString(), 'utf-8');
}

function waitOneSecond() {
    return new Promise(resolve => {
      setTimeout(() => {
        resolve();
      }, 1000);
    });
  }

async function waitProcess() {
    while(true) {
        await waitOneSecond()
        var ChatMode = readChatMode()
        if(ChatMode == 3) break
    }
}

async function readInputText() {
    const inputText = readFileSync('input.txt', 'utf-8')
    return inputText.trim();
}

var ChatMode = 0

await waitProcess()
const inputText = await readInputText()
console.log(inputText)
// ChatMode = await readChatMode()
// console(ChatMode)
// await setChatMode(10)