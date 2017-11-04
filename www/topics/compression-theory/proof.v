Require Import List.

Inductive char := Q | U | Other.

Fixpoint compress (cs : list char) : list char :=
  match cs with
    | Q :: U :: U :: cs' => Q :: U :: U :: U :: compress cs'
    | Q :: U :: cs'      => Q :: compress cs'
    | Q :: cs'           => Q :: U :: compress cs'
    | c :: cs'           => c :: compress cs'
    | nil                => nil
  end.

Fixpoint decompress (cs : list char) : list char :=
  match cs with
    | Q :: U :: cs'      => Q :: decompress cs'
    | Q :: cs'           => Q :: U :: decompress cs'
    | c :: cs'           => c :: decompress cs'
    | nil                => nil
  end.

Ltac destruct_chars :=
  repeat (
      match goal with
        | [ c : char |- _ ] => destruct c
      end ).

Theorem list_injection : forall {A} (a : A) (xs ys : list A), a :: xs = a :: ys -> xs = ys.
Proof.
  intros A a xs ys H; injection H; auto.
Qed.

Theorem it_works : forall (cs : list char), decompress (compress cs) = cs.
Proof.
  intro cs.
  induction cs as [ | c cs IH ]; try (destruct_chars; simpl; auto; fail).
  destruct c; try (simpl in *; repeat f_equal; auto; fail).
  destruct cs as [ | c cs ]; try (destruct_chars; simpl; auto; fail).
  destruct c; try (simpl in *; repeat f_equal; repeat (apply list_injection in IH); auto; fail).
  destruct cs as [ | c cs ]; try (destruct_chars; simpl; auto; fail).
  destruct c; try (simpl in *; repeat f_equal; repeat (apply list_injection in IH); auto; fail).
  destruct cs as [ | c cs ]; try (destruct_chars; simpl; auto; fail).
  destruct c; try (simpl in *; repeat f_equal; repeat (apply list_injection in IH); auto; fail).
  destruct cs as [ | c cs ]; try (destruct_chars; simpl; auto; fail).
  destruct c; try (simpl in *; repeat f_equal; repeat (apply list_injection in IH); auto; fail).
Qed.

  

  
  

  