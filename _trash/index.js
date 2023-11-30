// import { SchemaConverter }  from './public/json-schema-to-grammar.mjs'

// const in_prompt = `Help me with a simple calculation, I will give you a number, tell me the results of using it to time 10.`;
// const in_prompt = `I'm about traveling to Sydney, any advice?`;
const in_prompt = `I'd lile to use 12`;
// const prompt = `你曾经去过北京吗？`;

const chat = [
    {
        human: "Hello, Assistant.",
        assistant: "Hello. How may I help you today?"
    },
    {
        human: "Please tell me the largest city in Europe.",
        assistant: "Sure. The largest city in Europe is Moscow, the capital of Russia."
    },
]

const instruction = `A chat between a curious human and an artificial intelligence assistant. The assistant gives helpful, detailed, and polite answers to the human's questions.`

function format_prompt(question) {
    return `${instruction}\n${
        chat.map(m =>`### Human: ${m.human}\n### Assistant: ${m.assistant}`).join("\n")
    }\n### Human: ${question}\n### Assistant:`
}

async function Test() {
    let response = await fetch("http://127.0.0.1:8080/completion", {
        method: 'POST',
        body: JSON.stringify({
            prompt: format_prompt(in_prompt),
            temperature: 0.2,
            top_k: 40,
            top_p: 0.9,
            n_keep: -1,
            n_predict: 256,
            repeat_penalty: 1.1,
            n_predict: 100,
            cache_prompt: true,
            // slot_id: -1,
            stop: ["\n### Human:"], // stop completion after generating this
            // stream: true,
        })
    })
    console.log((await response.json()).content)
}

Test()