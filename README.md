# binary_obfuscator
I coded this project to strip any identifiable information from a Windows PE file.
The only technique(for now) built into it is obfuscating RTTI(run-time type information) strings. By obfuscating these, we prevent the leakage of C++ class names to the reverse engineer.

# TO-DO LIST:
-> Code Obfuscation & Virtualization.
-> PE Header Obfuscation.
