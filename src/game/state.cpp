#include <pch.hpp>

#include "game/state.hpp"

GameState::GameState()
    : m_WhiteCastleKingside(false), m_WhiteCastleQueenside(false), m_BlackCastleKingside(false),
      m_BlackCastleQueenside(false), m_EpSquare(-1), m_HalfmoveClock(0),
      m_LastMoveWasCapture(false), m_LastMoveWasPawnMove(false), m_WasEpCaptured(false),
      m_CapturedPieceType(PieceType::None),
      m_CapturedPiece(Piece(PieceType::None, PieceColor::White)),
      m_MovedPiece(Piece(PieceType::None, PieceColor::White)), m_MovedFrom(-1), m_MovedTo(-1),
      m_MoveFlag(0), m_RookPiece(Piece(PieceType::None, PieceColor::White)), m_RookFrom(-1),
      m_RookTo(-1) {}

GameState::GameState(bool wck, bool wcq, bool bck, bool bcq, int ep_square, int hmc)
    : m_WhiteCastleKingside(wck), m_WhiteCastleQueenside(wcq), m_BlackCastleKingside(bck),
      m_BlackCastleQueenside(bcq), m_EpSquare(ep_square), m_HalfmoveClock(hmc),
      m_LastMoveWasCapture(false), m_LastMoveWasPawnMove(false), m_WasEpCaptured(false),
      m_CapturedPieceType(PieceType::None),
      m_CapturedPiece(Piece(PieceType::None, PieceColor::White)),
      m_MovedPiece(Piece(PieceType::None, PieceColor::White)), m_MovedFrom(-1), m_MovedTo(-1),
      m_MoveFlag(0), m_RookPiece(Piece(PieceType::None, PieceColor::White)), m_RookFrom(-1),
      m_RookTo(-1) {}

GameState::GameState(const GameState& other)
    : m_WhiteCastleKingside(other.m_WhiteCastleKingside),
      m_WhiteCastleQueenside(other.m_WhiteCastleQueenside),
      m_BlackCastleKingside(other.m_BlackCastleKingside),
      m_BlackCastleQueenside(other.m_BlackCastleQueenside), m_EpSquare(other.m_EpSquare),
      m_HalfmoveClock(other.m_HalfmoveClock), m_LastMoveWasCapture(other.m_LastMoveWasCapture),
      m_LastMoveWasPawnMove(other.m_LastMoveWasPawnMove), m_WasEpCaptured(other.m_WasEpCaptured),
      m_CapturedPieceType(other.m_CapturedPieceType), m_CapturedPiece(other.m_CapturedPiece),
      m_MovedPiece(other.m_MovedPiece), m_MovedFrom(other.m_MovedFrom), m_MovedTo(other.m_MovedTo),
      m_MoveFlag(other.m_MoveFlag), m_RookPiece(other.m_RookPiece), m_RookFrom(other.m_RookFrom),
      m_RookTo(other.m_RookTo) {}