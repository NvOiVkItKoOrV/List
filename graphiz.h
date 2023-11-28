#if !defined(GRAPHVIZ_H)
#define GRAPHVIZ_H
    #define BEGIN(filePtr, name)    \
        fprintf(filePtr, "digraph %s {\n", #name);

    #define RANK_DIR(filePtr, arg)  \
        fprintf(filePtr, "\trankdir = %s;\n", #arg);

    #define GEN_MULTI_SECT_NODE_WITH_LABEL(filePtr, name, data, next, prev, label)  \
        if (name == 0) {                                                                                                                    \
            fprintf(filePtr, "\t %d [shape = record, label = \" %d | {| %s | <%d> %d | %d}\"];\n", name, name, ((char*) &data), label, next, prev);    \
        } else {                                                                                                                            \
            fprintf(filePtr, "\t %d [shape = record, label = \" %d | {| %d | <%d> %d | %d}\"];\n", name, name, data, label, next, prev);    \
        }

    #define GEN_MULTI_SECTION_NODE(filePtr, name, head, tale, ptrFree, size)        \
        fprintf(filePtr, "\t %s [shape = record, label = \" %d head | %d tale | %d free | %d size \"];\n", #name, head, tale, ptrFree, size);
    #define GEN_OF_ARROW(filePtr, nameOf1Node, nameOf2Node, label, label1)          \
        fprintf(filePtr, "\t%d: <%d> -> %d: <%d>;\n", nameOf1Node, label, nameOf2Node, label1);

    #define END(filePtr)        \
        fprintf(filePtr, "}");  \
        fclose(filePtr);

    #define GEN_OF_PNG  \
        system("dot -Tpng ListDump.dot -o listDump.png");
#endif // GRAPHVIZ_H
