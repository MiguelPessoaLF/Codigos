--
-- PostgreSQL database dump
--

-- Dumped from database version 14.18 (Ubuntu 14.18-0ubuntu0.22.04.1)
-- Dumped by pg_dump version 14.18 (Ubuntu 14.18-0ubuntu0.22.04.1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: X; Type: TABLE; Schema: public; Owner: ti2cc
--

CREATE TABLE public."X" (
    a integer NOT NULL,
    b integer NOT NULL
);


ALTER TABLE public."X" OWNER TO ti2cc;

--
-- Name: TABLE "X"; Type: COMMENT; Schema: public; Owner: ti2cc
--

COMMENT ON TABLE public."X" IS 'Tabela X';


--
-- Name: X_a_seq; Type: SEQUENCE; Schema: public; Owner: ti2cc
--

CREATE SEQUENCE public."X_a_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."X_a_seq" OWNER TO ti2cc;

--
-- Name: X_a_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: ti2cc
--

ALTER SEQUENCE public."X_a_seq" OWNED BY public."X".a;


--
-- Name: X_b_seq; Type: SEQUENCE; Schema: public; Owner: ti2cc
--

CREATE SEQUENCE public."X_b_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."X_b_seq" OWNER TO ti2cc;

--
-- Name: X_b_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: ti2cc
--

ALTER SEQUENCE public."X_b_seq" OWNED BY public."X".b;


--
-- Name: X a; Type: DEFAULT; Schema: public; Owner: ti2cc
--

ALTER TABLE ONLY public."X" ALTER COLUMN a SET DEFAULT nextval('public."X_a_seq"'::regclass);


--
-- Name: X b; Type: DEFAULT; Schema: public; Owner: ti2cc
--

ALTER TABLE ONLY public."X" ALTER COLUMN b SET DEFAULT nextval('public."X_b_seq"'::regclass);


--
-- Data for Name: X; Type: TABLE DATA; Schema: public; Owner: ti2cc
--

INSERT INTO public."X" VALUES (1, 1);
INSERT INTO public."X" VALUES (1, 2);
INSERT INTO public."X" VALUES (2, 2);
INSERT INTO public."X" VALUES (3, 3);


--
-- Name: X_a_seq; Type: SEQUENCE SET; Schema: public; Owner: ti2cc
--

SELECT pg_catalog.setval('public."X_a_seq"', 3, true);


--
-- Name: X_b_seq; Type: SEQUENCE SET; Schema: public; Owner: ti2cc
--

SELECT pg_catalog.setval('public."X_b_seq"', 3, true);


--
-- PostgreSQL database dump complete
--

